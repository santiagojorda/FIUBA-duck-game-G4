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

    Texture background(renderer, DATA_PATH "/background.png");

    client_game_state_t actual_game_state;

    std::cout << "antes de iniciar partida\n";

    auto chrono_now = std::chrono::high_resolution_clock::now();
    auto chrono_prev = chrono_now;

    // desde el LOBBY ya le di a startear game, por lo tanto no necesito darle a la "m", de entrada recibo la data
    // lo traigo para acá así no hay drama

    //Socket skt("localhost", "8080");
    //ClientProtocol protocol(skt);
    //protocol.send_init(0xFF);

    // ---------------------------- Iniciar partida primer escenario ----------------------------
    // Mientras no reciba un primer escenario, queda en el ciclo
    while (!game_state.try_pop(actual_game_state)) {
        std::cout << "cargando partida...!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        player_t player = actual_game_state.players[i];
        drawer_players[player.sprite.id_texture] = std::make_unique<DrawerPlayer>(renderer, player);
        drawer_players[player.sprite.id_texture]->draw(renderer, player);
    }

    // -----------------------------------------------------------------------------------------
    while (true) {  // receiver del cliente

        while (game_state.try_pop(actual_game_state)) {}

        renderer.Clear();

        renderer.Copy(background, Rect(0, 0, renderer.GetOutputWidth(), renderer.GetOutputHeight()));
        // ---------------------------- Draw Patos ----------------------------
        for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            player_t player = actual_game_state.players[i];
            drawer_players[player.sprite.id_texture]->draw(renderer, player);
        }

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
