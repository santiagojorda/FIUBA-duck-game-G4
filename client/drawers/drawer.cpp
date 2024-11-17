#include "drawer.h"

#include <chrono>

using namespace SDL2pp;

Drawer::Drawer(Queue<ClientEvent_t>& commands, Queue<client_game_state_t>& game_state):
        commands(commands), game_state(game_state), keyboard_controller(commands, 1) {}

void Drawer::run() try {
    SDL sdl(SDL_INIT_VIDEO);

    Window window(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                  WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);


    Texture background(renderer, DATA_PATH "/background.png");

    // chain bullet
    Texture bala_r(renderer, DATA_PATH "/DuckGame-MachineGuns.png");

    // shell creo que este era escopeta (?)
    Texture bala_shell(renderer, DATA_PATH "/DuckGame-Shotguns.png");

    // de laser
    Texture bala_laser(renderer, DATA_PATH "/DuckGame-Laser.png");


    drawers_t drawers;
    client_game_state_t actual_game_state;

    auto chrono_now = std::chrono::high_resolution_clock::now();
    auto chrono_prev = chrono_now;

    // desde el LOBBY ya le di a startear game, por lo tanto no necesito darle a la "m", de entrada
    // recibo la data lo traigo para acá así no hay drama

    Socket skt("localhost", "8080");
    ClientProtocol protocol(skt);
    protocol.send_init(0xFF);

    // ---------------------------- Iniciar partida primer escenario ----------------------------
    // Mientras no reciba un primer escenario, queda en el ciclo
    while (!game_state.try_pop(actual_game_state)) {
        std::cout << "Loading..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS));
    }

    init_scenery(renderer, actual_game_state, drawers);

    // -----------------------------------------------------------------------------------------
    while (true) {

        while (game_state.try_pop(actual_game_state)) {}

        renderer.Clear();

        renderer.Copy(background, Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

        // X=2, Y=205, 8x8
        renderer.Copy(bala_r, SDL2pp::Rect(2, 205, 8, 8), SDL2pp::Rect(WINDOW_WIDTH / 2, 199, 10, 10));

        // balas laser
        renderer.Copy(bala_laser, SDL2pp::Rect(2, 205, 8, 8), SDL2pp::Rect(WINDOW_WIDTH / 2, 199, 10, 10));

        // Draw Players (Patos)
        for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            auto player = actual_game_state.players[i];
            drawers.players[player.sprite.id_texture] =
                    std::make_unique<DrawerPlayer>(renderer, player);
            drawers.players[player.sprite.id_texture]->draw(renderer, player);
        }

        for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            player_t player = actual_game_state.players[i];
            drawers.players[player.sprite.id_texture]->draw(renderer, player);
        }

        // Draw Floor
        if (drawers.floors.size() != actual_game_state.floors.size()) {
            drawers.floors.resize(actual_game_state.floors.size());

            for (size_t i = 0; i < actual_game_state.floors.size(); ++i) {
                if (!drawers.floors[i]) {
                    auto floor = actual_game_state.floors[i];
                    drawers.floors[i] = std::make_unique<DrawerFloor>(renderer, floor);
                }
            }
        }

        for (size_t i = 0; i < actual_game_state.floors.size(); ++i) {
            auto floor = actual_game_state.floors[i];
            drawers.floors[i]->draw(renderer, floor);
        }

        // Draw Box
        if (drawers.boxes.size() != actual_game_state.boxs.size()) {
            drawers.boxes.resize(actual_game_state.boxs.size());
            for (size_t i = 0; i < actual_game_state.boxs.size(); ++i) {
                if (!drawers.boxes[i]) {
                    auto box = actual_game_state.boxs[i];
                    drawers.boxes[i] = std::make_unique<DrawerBox>(renderer, box);
                }
            }
        }

        for (size_t i = 0; i < actual_game_state.boxs.size(); ++i) {
            auto box = actual_game_state.boxs[i];
            drawers.boxes[i]->draw(renderer, box);
        }

        // Draw Weapon
        if (drawers.weapons.size() != actual_game_state.weapons.size()) {
            drawers.weapons.resize(actual_game_state.weapons.size());
            for (size_t i = 0; i < actual_game_state.weapons.size(); ++i) {
                if (!drawers.weapons[i]) {
                    auto weapon = actual_game_state.weapons[i];
                    drawers.weapons[i] = std::make_unique<DrawerWeapon>(renderer, weapon);
                }
            }
        }

        for (size_t i = 0; i < actual_game_state.weapons.size(); ++i) {
            auto weapon = actual_game_state.weapons[i];
            drawers.weapons[i]->draw(renderer, weapon);
        }

        // Fin draw, lo presentamos.
        renderer.Present();

        chrono_now = std::chrono::high_resolution_clock::now();
        auto delta_chrono = (chrono_now - chrono_prev);
        if (delta_chrono < std::chrono::milliseconds(MILISECONDS_30_FPS)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS));
        }

        chrono_prev = std::chrono::high_resolution_clock::now();

        SDL_Event event;
        keyboard_controller.procesar_comando(event);
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}

void Drawer::init_scenery(Renderer& renderer, const client_game_state_t& actual_game_state,
                          drawers_t& drawers) {
    // Player
    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        auto player = actual_game_state.players[i];
        drawers.players[player.sprite.id_texture] =
                std::make_unique<DrawerPlayer>(renderer, player);
        drawers.players[player.sprite.id_texture]->draw(renderer, player);
    }

    // Floor
    for (size_t i = 0; i < actual_game_state.floors.size(); i++) {
        auto floor = actual_game_state.floors[i];
        drawers.floors.push_back(std::make_unique<DrawerFloor>(renderer, floor));
        drawers.floors.back()->draw(renderer, floor);
    }

    // Box
    for (size_t i = 0; i < actual_game_state.boxs.size(); i++) {
        auto box = actual_game_state.boxs[i];
        drawers.boxes.push_back(std::make_unique<DrawerBox>(renderer, box));
        drawers.boxes.back()->draw(renderer, box);
    }

    // Weapon
    for (size_t i = 0; i < actual_game_state.weapons.size(); i++) {
        auto weapon = actual_game_state.weapons[i];
        drawers.weapons.push_back(std::make_unique<DrawerWeapon>(renderer, weapon));
        drawers.weapons.back()->draw(renderer, weapon);
    }
}
