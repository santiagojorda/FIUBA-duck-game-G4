#include "drawer.h"

#include "../../common/sleep_special.h"

using namespace SDL2pp;

Drawer::Drawer(Queue<ClientEvent_t>& commands, Queue<client_game_state_t>& game_state):
        commands(commands), game_state(game_state), keyboard_controller(commands, 2) {}

void Drawer::run() try {
    SDL sdl(SDL_INIT_VIDEO);

    Window window(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                  WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    Texture main_texture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH,
                         WINDOW_HEIGHT);

    main_texture.SetBlendMode(SDL_BLENDMODE_BLEND);

    Texture background(renderer, DATA_PATH "/background.png");

    SleepSpecial sleep(MILISECONDS_30_FPS);
    int iteration = 0;
    drawers_t drawers;
    client_game_state_t actual_game_state;

    ZoomHandler zoom_handler;
    // desde el LOBBY ya le di a startear game, por lo tanto no necesito darle a la "m", de entrada
    // recibo la data lo traigo para acá así no hay drama

    // Socket skt("localhost", "8080");
    // ClientProtocol protocol(skt);
    // protocol.send_init(0xFF);

    // ---------------------------- Iniciar partida primer escenario ----------------------------
    // Mientras no reciba un primer escenario, queda en el ciclo
    /*while (!game_state.try_pop(actual_game_state)) { TODO: cambiar a pop
         std::cout << "Loading..." << std::endl;
         std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS));
     }*/

    // -----------------------------------------------------------------------------------------
    while (true) {

        while (game_state.try_pop(actual_game_state)) {}
        renderer.Clear();

        renderer.Copy(background, Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

        SDL_SetRenderTarget(renderer.Get(), main_texture.Get());

        renderer.SetDrawColor(0, 0, 0, 0);

        renderer.Clear();

        init_scenery(renderer, actual_game_state, drawers);

        // Draw Players (Patos)
        /*for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            auto player = actual_game_state.players[i];
            drawers.players[player.sprite.id_texture] =
                    std::make_unique<DrawerPlayer>(renderer, player);
            drawers.players[player.sprite.id_texture]->draw(renderer, player);
        }*/

        for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            player_t player = actual_game_state.players[i];
            drawers.players[player.sprite.id_texture]->draw(player);
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

        SDL_SetRenderTarget(renderer.Get(), nullptr);

        zoom_handler.calculate_zoom(actual_game_state.players);
        zoom_handler.apply_zoom(renderer, main_texture);
        renderer.Present();

        sleep.sleep_rate(iteration);

        SDL_Event event;
        keyboard_controller.procesar_comando(event);
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}

void Drawer::init_scenery(Renderer& renderer, const client_game_state_t& actual_game_state,
                          drawers_t& drawers) {
    // Player
    if (actual_game_state.players.size() == drawers.players.size()) {
        return;
    }

    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        auto player = actual_game_state.players[i];
        drawers.players[player.sprite.id_texture] =
                std::make_unique<DrawerPlayer>(renderer, player.sprite.id_texture, player);
        drawers.players[player.sprite.id_texture]->draw(player);
    }
    /*
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
        }*/
}
