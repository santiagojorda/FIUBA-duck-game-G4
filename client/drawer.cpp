#include "drawer.h"

#include <chrono>

// Game
#define GAME_TITLE "Duck Game"

// Window
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling

// (X,Y) DEL PATO PARA ESTAR QUIETO Y CAMINAR DEL SPRITE
#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32
#define CANT_ANIMATION_RUN 6  // para la fase de animacion

// FLOOR
#define SIZE_FLOOR_SPRITE 16

// VELOCIDAD: si lo aumento, aumenta la velocidad
#define VELOCIDAD_SPRITES 0.2

// POSICION INICIAL JUGADOR : en realidad lo recibo del servidor :)
#define POSITION_PLAYER_X
#define POSITION_PLAYER_Y

// ALA DEL PATO en SPRITE -> las alas empiezan desde Y= 518, voy a suponer que miden 16x16
#define ALA_INITIAL_X 1
#define ALA_INITIAL_Y 518

using namespace SDL2pp;

Drawer::Drawer(Queue<ClientEvent_t>& commands, Queue<std::vector<PlayerPosition_t>>& positions):
        commands(commands), positions(positions), keyboard_controller(commands) {}

/**
 * Recibo
 * tipo de arma
 * tipode jugador
 * tipo de disparo
 *
 */

void Drawer::run() try {
    SDL sdl(SDL_INIT_VIDEO);

    Window window(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                  WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    // Crear la textura principal como un render target

    // Load sprites image as a new texture
    Texture sprites(renderer, DATA_PATH "/DuckGame-YellowDuck.png");

    // Load background image as a new texture
    Texture background(renderer, DATA_PATH "/background.png");

    // Load tileset image as a new texture
    Texture floor(renderer, DATA_PATH "/NatureTileset.png");

    // Load pistol image as a new texture
    Texture pistol_magnum(renderer, DATA_PATH "/DuckGame-Pistol.png");

    // Load ala pato image as a new texture
    Texture ala_duck(renderer, DATA_PATH "/DuckGame-YellowDuck.png");

    // Variables de animación
    // podemos calcular el tiempo transcurrido desde la última actualización de animación, lo que te
    // permite cambiar de fase de animación solo después de un cierto intervalo, sin depender de
    // un bucle
    auto last_animation_time = std::chrono::high_resolution_clock::now();  // tiempo inicial
    const std::chrono::milliseconds animation_interval(100);  // 100ms entre cuadros de animación

    // Game state
    bool is_running = false;
    bool is_moving_left = false;
    unsigned int run_phase = 0;  // fase de animación

    std::vector<PlayerPosition_t> position;

    // SDL_Event event_init;
    //  Se envia la tecla que presionó el usuario

    // keyboard_controller.procesar_comando(event_init, is_running, is_moving_left);

    while (true) {  // receiver del cliente
        // position = positions.pop();

        while (positions.try_pop(position)) {


            renderer.Clear();

            
            // ---------------------------- Draw BACKGROUND ----------------------------
            renderer.Copy(background,
                          Rect(0, 0, renderer.GetOutputWidth(), renderer.GetOutputHeight()));

            // ---------------------------- Draw PISO TILESET ----------------------------

            int center_y = renderer.GetOutputHeight() / 2;  // Y coordinate of window center
            int center_x = renderer.GetOutputWidth() / 2;

            // Cantidad de tiles que se necesitan de forma horizontal
            int num_tiles_x = renderer.GetOutputWidth() / TILE_SIZE + 1;

            for (int i = 0; i < num_tiles_x; ++i) {
                // Lo multiplico por 3 porque solo estoy tomando el 3 tileset en x, pero es de la
                // fila 1
                // => y = 0
                // TILE_SIZE - 42 motivo: el tamaño del pato menos ojimetro
                renderer.Copy(
                        floor, Rect(SIZE_FLOOR_SPRITE * 3, 0, SIZE_FLOOR_SPRITE, SIZE_FLOOR_SPRITE),
                        Rect(i * TILE_SIZE, center_y - (TILE_SIZE - 42), TILE_SIZE, TILE_SIZE));
            }

            // ---------------------------- Draw PISTOLA ----------------------------
            int magnum_x = 1;
            int magnum_y = 47;
            renderer.Copy(pistol_magnum, Rect(magnum_x, magnum_y, 32, 32),
                          Rect(center_x, center_y - 41, TILE_SIZE, TILE_SIZE));


            // ---------------------------- Draw Player ----------------------------
            // Primer Rect (x, y, w, h): (x, y) toman una coordenada de la imagen (w, h) le
            // indicamos el alto y ancho Segundo Rect (x, y, w, h): le indicamos en que parte de la
            // pantalla aparece, y el tamaño

            // ---------------------------- Animación del Pato ----------------------------


            auto now = std::chrono::high_resolution_clock::now();
            /**
             * chequeamos que el pato está corriendo y el tiempo que pasó entre la última animación
             *  y el tiempo actual. si superó el intervalo, se actualiza la animación y
             * el tiempo de la última animación para aplicar el mismo ciclos en los siguientes
             * sprites.
             */
            if (is_running && now - last_animation_time >= animation_interval) {
                /**
                 * El valor de run_phase representa el índice de la
                 * fase actual de animación. Cada vez que pasa el intervalo de tiempo, run_phase se
                 * incrementa y se ajusta usando el operador módulo (% CANT_ANIMATION_RUN) para
                 * ciclar entre los frames de animación disponibles.
                 *
                 */
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

            /*
            // ---------------------------- Draw PISTOLA ENCIMA DEL PATO----------------------------

            renderer.Copy(pistol_magnum, Rect(magnum_x, magnum_y, 32, 32),
                          Rect((int)position, center_y - (TILE_SIZE - 2), TILE_SIZE, TILE_SIZE),
            0.0, SDL2pp::NullOpt, flip);

            // ------------------ Draw ALA DEL PATO ENCIMA DEL PATO ------------------

            renderer.Copy(ala_duck, Rect(ALA_INITIAL_X, ALA_INITIAL_Y + (16 * 5), 16, 16),
                          Rect((int)position + 7, center_y - (TILE_SIZE) + 15, 20, 20), 0.0,
                          SDL2pp::NullOpt, flip);
            */

            renderer.Present();
        }

        SDL_Event event;
        // Se envia la tecla que presionó el usuario
        keyboard_controller.procesar_comando(event, is_running, is_moving_left);
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
