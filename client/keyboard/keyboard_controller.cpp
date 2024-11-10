#include "keyboard_controller.h"

KeyboardController::KeyboardController(Queue<ClientEvent_t>& _commands, int _num_players):
        commands(_commands), num_players(_num_players) {}

enum PlayerKeyboard { PLAYER_1, PLAYER_2 };

/*
    Protocol enviar

    0 o 1
    <HEADER_JUGADOR> <id_jugador>,<id_movimiento>... <etc>
*/

void KeyboardController::procesar_comando(SDL_Event& event, bool& is_running,
                                          bool& is_moving_left) {
    while (SDL_PollEvent(&event)) {  // este es un Sender :) se envian los datos al servidor

        if (event.type == SDL_QUIT) {
            throw std::runtime_error("Cierre del juego");
        }

        // Este evento ocurre cuando una tecla es presionada
        if (event.type == SDL_KEYDOWN) {
            procesar_keydown(event, is_running, is_moving_left);
            // Este evento ocurre cuando la tecla es liberada
        } else if (event.type == SDL_KEYUP) {
            procesar_keyup(event, is_running);
        }
    }
}

void KeyboardController::procesar_keyup(SDL_Event& event, bool& is_running) {
    switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
            is_running = false;
            break;
        case SDLK_LEFT:
            is_running = false;
            break;
    }
}

void KeyboardController::procesar_keydown(SDL_Event& event, bool& is_running,
                                          bool& is_moving_left) {
    switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
        case SDLK_q:
            throw std::runtime_error("Cierre del juego");
        case SDLK_m:  // tecla m : Iniciar juego
            try {
                std::cout << "Presiono m" << std::endl;

                Socket skt("localhost", "8080");
                ClientProtocol protocol(skt);
                protocol.send_init(0xFF);
                std::cout << "iniciar juego" << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "error en case " << e.what() << '\n';
            }

            break;
        case SDLK_RIGHT:
        case SDLK_LEFT:
        case SDLK_UP:
        case SDLK_SPACE:
        case SDLK_e:
        case SDLK_f:
        case SDLK_DOWN:
            procesar_accion_player_1(event, is_running, is_moving_left);
            break;
        default:
            if (num_players == 2) {
                procesar_accion_player_2(event, is_running, is_moving_left);
            }
            break;
    }
}

void KeyboardController::procesar_accion_player_1(SDL_Event& event, bool& is_running,
                                                  bool& is_moving_left) {
    ClientEvent_t client_event;
    switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
            is_running = true;
            is_moving_left = false;
            client_event = {PLAYER_1, MOVE_RIGHT};
            this->commands.push(client_event);
            break;
        case SDLK_LEFT:
            is_running = true;
            is_moving_left = true;
            client_event = {PLAYER_1, MOVE_LEFT};
            this->commands.push(client_event);
            break;
        case SDLK_UP:
            client_event = {PLAYER_1, JUMP};
            this->commands.push(client_event);
            std::cout << "Saltar" << std::endl;
            break;
        case SDLK_SPACE:  // disparar espacio
            std::cout << "Disparar" << std::endl;
            break;
        case SDLK_e:  // recoger o soltar un arma/objeto
            std::cout << "Tomar/soltar objeto" << std::endl;
            break;
        case SDLK_f:  // apuntar hacia arriba
            std::cout << "Apuntando hacia arriba" << std::endl;
            break;
        case SDLK_DOWN:  // flecha hacia abajo para agacharse
            client_event = {PLAYER_1, CROUCH};
            this->commands.push(client_event);
            std::cout << "Agacharse" << std::endl;
            break;
    }
}

void KeyboardController::procesar_accion_player_2(SDL_Event& event, bool& is_running,
                                                  bool& is_moving_left) {
    ClientEvent_t client_event;
    switch (event.key.keysym.sym) {
        case SDLK_d:
            is_running = true;
            is_moving_left = false;
            client_event = {PLAYER_2, MOVE_RIGHT};
            this->commands.push(client_event);
            break;
        case SDLK_a:
            is_running = true;
            is_moving_left = true;
            client_event = {PLAYER_2, MOVE_LEFT};
            this->commands.push(client_event);
            break;
        case SDLK_w:  // tecla W para saltar
            client_event = {PLAYER_2, JUMP};
            this->commands.push(client_event);
            std::cout << "Saltar (Jugador 2)" << std::endl;
            break;
        case SDLK_s:  // tecla S para agacharse
            client_event = {PLAYER_2, CROUCH};
            this->commands.push(client_event);
            std::cout << "Agacharse (Jugador 2)" << std::endl;
            break;
    }
}