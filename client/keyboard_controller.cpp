#include "keyboard_controller.h"

#include "../common/action_commands.h"

KeyboardController::KeyboardController(Queue<uint8_t>& _commands): commands(_commands) {}

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
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    throw std::runtime_error("Cierre del juego");
                case SDLK_q:
                    throw std::runtime_error("Cierre del juego");
                    return;
                case SDLK_RIGHT:  // flecha hacia la derecha
                    is_running = true;
                    is_moving_left = false;
                    this->commands.push(MOVE_RIGHT);
                    break;
                case SDLK_LEFT:  // flecha hacia la izquierda
                    is_running = true;
                    is_moving_left = true;
                    this->commands.push(MOVE_LEFT);
                    break;
                case SDLK_UP:  // flecha hacia arriba para saltar
                    std::cout << "Saltar" << std::endl;
                    break;
                case SDLK_SPACE:  // disparar espacio
                    std::cout << "Disparar" << std::endl;
                    break;
                case SDLK_e:  // recoger o soltar un arma/objeto
                    std::cout << "Tomar/soltar objeto" << std::endl;
                    break;
                case SDLK_w:  // apuntar hacia arriba
                    std::cout << "Apuntando hacia arriba" << std::endl;
                    break;
                case SDLK_DOWN:  // flecha hacia abajo para agacharse
                    std::cout << "Agacharse" << std::endl;
                    break;
            }
            // Este evento ocurre cuando la tecla es liberada
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    is_running = false;
                    break;
                case SDLK_LEFT:
                    is_running = false;
                    break;
            }
        }
    }
}
