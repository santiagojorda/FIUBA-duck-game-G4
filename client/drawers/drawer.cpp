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

    std::map<uint8_t, std::unique_ptr<DrawerPlayer>> drawer_players;
    std::vector<std::unique_ptr<DrawerFloor>> drawer_floor;
    std::vector<std::unique_ptr<DrawerBox>> drawer_boxes;


    std::vector<std::shared_ptr<DrawerPlayer>> drawer_ducks;
    std::vector<std::shared_ptr<DrawerWeapon>> drawer_weapons;


    Texture background(renderer, DATA_PATH "/background.png");

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
        std::cout << "Cargando partida..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS));
    }

    // Player
    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        auto player = actual_game_state.players[i];
        drawer_players[player.sprite.id_texture] = std::make_unique<DrawerPlayer>(renderer, player);
        drawer_players[player.sprite.id_texture]->draw(renderer, player);
    }

    // Floor
    for (size_t i = 0; i < actual_game_state.floors.size(); i++) {
        auto floor = actual_game_state.floors[i];
        drawer_floor.push_back(std::make_unique<DrawerFloor>(renderer, floor));
        drawer_floor.back()->draw(renderer, floor);
    }

    // -----------------------------------------------------------------------------------------
    while (true) {

        while (game_state.try_pop(actual_game_state)) {}

        renderer.Clear();

        renderer.Copy(background, Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

        // Draw Players (Patos)
        for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            player_t player = actual_game_state.players[i];
            drawer_players[player.sprite.id_texture]->draw(renderer, player);
        }

        // Draw Floor
        if (drawer_floor.size() != actual_game_state.floors.size()) {
            drawer_floor.resize(actual_game_state.floors.size());

            for (size_t i = 0; i < actual_game_state.floors.size(); ++i) {
                if (!drawer_floor[i]) {
                    auto floor = actual_game_state.floors[i];
                    drawer_floor[i] = std::make_unique<DrawerFloor>(renderer, floor);
                }
            }
        }

        for (size_t i = 0; i < actual_game_state.floors.size(); ++i) {
            auto floor = actual_game_state.floors[i];
            drawer_floor[i]->draw(renderer, floor);
        }

        /*
                        // ---------------------------- Draw Boxes ----------------------------
                // Esto si puede variar.....
                if (drawer_boxes.size() != _game_state.boxs.size()) {
                    drawer_boxes.resize(_game_state.boxs.size());
                    for (size_t i = 0; i < _game_state.boxs.size(); ++i) {
                        if (!drawer_boxes[i]) {
                            auto box = _game_state.boxs[i];
                            drawer_boxes[i] = std::make_shared<DrawerBox>(box, renderer);
                        }
                    }
                }
                for (size_t i = 0; i < _game_state.boxs.size(); ++i) {
                    auto box = _game_state.boxs[i];
                    drawer_boxes[i]->update_box(box);
                    drawer_boxes[i]->draw(renderer);
                }
                // ---------------------------- Draw Weapons ----------------------------
                if (drawer_weapons.size() != _game_state.weapons.size()) {
                    drawer_weapons.resize(_game_state.weapons.size());
                    for (size_t i = 0; i < _game_state.weapons.size(); ++i) {
                        if (!drawer_weapons[i]) {
                            auto weapon = _game_state.weapons[i];
                            drawer_weapons[i] = std::make_shared<DrawerWeapon>(weapon, renderer);
                        }
                    }
                }
                for (size_t i = 0; i < _game_state.weapons.size(); ++i) {
                    auto weapon = _game_state.weapons[i];
                    drawer_weapons[i]->update_weapon(weapon);
                    drawer_weapons[i]->draw(renderer);
                }
        */

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
