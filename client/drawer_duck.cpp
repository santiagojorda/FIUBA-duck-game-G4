#include "drawer_duck.h"

// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling


// (X,Y) DEL PATO PARA ESTAR QUIETO Y CAMINAR DEL SPRITE
#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32
#define CANT_ANIMATION_RUN 6  // para la fase de animacion

DrawerDuck::DrawerDuck(SDL2pp::Renderer& renderer):
        texture(renderer, DATA_PATH "/DuckGame-YellowDuck.png"),
        x(0),
        y(0),
        run_phase(0),
        last_animation_time(std::chrono::high_resolution_clock::now()),
        animation_interval(100) {}

void DrawerDuck::update_animation(bool isRunning) {
    auto now = std::chrono::high_resolution_clock::now();
    if (isRunning && now - last_animation_time >= animation_interval) {
        run_phase = (run_phase + 1) % CANT_ANIMATION_RUN;
        last_animation_time = now;
    } else if (!isRunning) {
        run_phase = 0;
    }
}

void DrawerDuck::draw(SDL2pp::Renderer& renderer, bool is_moving_left) {
    int src_x = DUCK_INITIAL_X + SIZE_DUCK_SPRITE * run_phase;
    int src_y = DUCK_INITIAL_Y;
    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                  SDL2pp::Rect(x, y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                  is_moving_left ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void DrawerDuck::set_position(int new_X, int new_Y) {
    x = new_X;
    y = new_Y;
}

/**
 *     // Variables de animación
    // podemos calcular el tiempo transcurrido desde la última actualización de animación, lo que te
    // permite cambiar de fase de animación solo después de un cierto intervalo, sin depender de
    // un bucle
    auto last_animation_time = std::chrono::high_resolution_clock::now();  // tiempo inicial
    const std::chrono::milliseconds animation_interval(100);  // 100ms entre cuadros de animación
 *
 *  // ---------------------------- Animación del Pato ----------------------------


            auto now = std::chrono::high_resolution_clock::now();

             * chequeamos que el pato está corriendo y el tiempo que pasó entre la última animación
             *  y el tiempo actual. si superó el intervalo, se actualiza la animación y
             * el tiempo de la última animación para aplicar el mismo ciclos en los siguientes
             * sprites.

            if (is_running && now - last_animation_time >= animation_interval) {

                 * El valor de run_phase representa el índice de la
                 * fase actual de animación. Cada vez que pasa el intervalo de tiempo, run_phase se
                 * incrementa y se ajusta usando el operador módulo (% CANT_ANIMATION_RUN) para
                 * ciclar entre los frames de animación disponibles.
                 *

                run_phase = (run_phase + 1) % CANT_ANIMATION_RUN;
                last_animation_time = now;  // actualizar el tiempo de última animación
            } else if (!is_running) {
                run_phase = 0;  // fijar en el primer cuadro si no se mueve
            }

            int src_x = DUCK_INITIAL_X + SIZE_DUCK_SPRITE * run_phase;  // Sprite actual
            int src_y = DUCK_INITIAL_Y;

            // para varios patos
            for (const auto& pos: position) {
                renderer.Copy(sprites,
                              Rect(src_x, src_y, SIZE_DUCK_SPRITE,
                                   SIZE_DUCK_SPRITE),  // position en Sprite
                              Rect(pos.coordinate.get_x(), pos.coordinate.get_y(), TILE_SIZE,
                                   TILE_SIZE),  // position en pantalla
                              0.0,              // no rotation
                              SDL2pp::NullOpt,  // no center for rotation
                              is_moving_left ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            }
 *
 */
