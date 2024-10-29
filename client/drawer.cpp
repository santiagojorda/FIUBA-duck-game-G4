#include "drawer.h"

// Game
#define GAME_TITLE "Duck Game"

// Window
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling

// (X,Y) DEL PATO PARA ESTAR QUIETO Y CAMINAR
#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32
#define CANT_ANIMATION_RUN 6

// FLOOR
#define SIZE_FLOOR_SPRITE 16

using namespace SDL2pp;

Drawer::Drawer(): keyboard_controller() {}

void Drawer::run() try {
    SDL sdl(SDL_INIT_VIDEO);

    Window window(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                  WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load sprites image as a new texture
    Texture sprites(renderer, DATA_PATH "/DuckGame-YellowDuck.png");

    // Load background image as a new texture
    Texture background(renderer, DATA_PATH "/background.png");

    // Load tileset image as a new texture
    Texture floor(renderer, DATA_PATH "/NatureTileset.png");

    // Load pistol image as a new texture
    Texture pistol(renderer, DATA_PATH "/DuckGame-Pistol.png");

    // Game state
    bool is_running = false;
    bool is_moving_left = false;

    int run_phase = -1;    // run animation phase
    float position = 0.0;  // player position

    unsigned int prev_ticks = SDL_GetTicks();  // an unsigned 32-bit value representing the number
                                               // of milliseconds since the SDL library initialized.


    while (true) {  // receiver del cliente
        // Timing: calculate difference between this and previous frame
        // in milliseconds
        unsigned int frame_ticks = SDL_GetTicks();
        unsigned int frame_delta = frame_ticks - prev_ticks;
        prev_ticks = frame_ticks;


        SDL_Event event;
        keyboard_controller.procesar_comando(event, is_running, is_moving_left);

        // Update game state for this frame:
        // if character is runnung, move it to the right

        // ---------------------------- Control Pato hacia izquierda o derecha
        // ----------------------------
        if (is_running) {
            if (is_moving_left) {
                position -= frame_delta *
                            0.2;  // move left si aumento el porcentaje, aumenta la velocidad
            } else {
                position += frame_delta * 0.2;  // move right
            }
            run_phase = (frame_ticks / 100) %
                        CANT_ANIMATION_RUN;  // animation phase. frame_ticks es la posicion
                                             // actual dividido la cantidad de imagenes
        } else {
            run_phase = 0;
        }

        // If player passes past the right or left side of the window, wrap
        if (position > renderer.GetOutputWidth()) {
            position = -TILE_SIZE;  // wrap from the right
        } else if (position < -TILE_SIZE) {
            position = renderer.GetOutputWidth();  // wrap from the left
        }

        int vcenter = renderer.GetOutputHeight() / 2;  // Y coordinate of window center

        // Clear screen
        renderer.Clear();

        // ---------------------------- Draw BACKGROUND ----------------------------
        renderer.Copy(background,
                      Rect(0, 0, renderer.GetOutputWidth(), renderer.GetOutputHeight()));

        // ---------------------------- Draw PISO TILESET ----------------------------

        // Cantidad de tiles que se necesitan de forma horizontal
        int num_tiles_x = renderer.GetOutputWidth() / TILE_SIZE + 1;

        for (int i = 0; i < num_tiles_x; ++i) {
            // Lo multiplico por 3 porque solo estoy tomando el 3 tileset en x, pero es de la fila 1
            // => y = 0
            renderer.Copy(floor,
                          Rect(SIZE_FLOOR_SPRITE * 3, 0, SIZE_FLOOR_SPRITE, SIZE_FLOOR_SPRITE),
                          Rect(i * TILE_SIZE, vcenter - (TILE_SIZE - 42), TILE_SIZE, TILE_SIZE));
        }

        // ---------------------------- Draw Player ----------------------------
        // Player is running and run animation phase
        int src_x = DUCK_INITIAL_X, src_y = DUCK_INITIAL_Y;  // by default, standing sprite
        if (is_running) {
            src_x = DUCK_INITIAL_X + SIZE_DUCK_SPRITE * run_phase;
            // src_y = DUCK_INITIAL_Y;
        }

        // Flip the sprite if moving left
        SDL_RendererFlip flip = is_moving_left ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

        // Primer Rect (x, y, w, h): (x, y) toman una coordenada de la imagen (w, h) le indicamos el
        // alto y ancho Segundo Rect (x, y, w, h): le indicamos en que parte de la pantalla aparece,
        // y el tamaño

        renderer.Copy(sprites, Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      Rect((int)position, vcenter - TILE_SIZE, TILE_SIZE, TILE_SIZE),
                      0.0,              // no rotation
                      SDL2pp::NullOpt,  // no center for rotation
                      flip              // flip horizontally if moving left
        );

        renderer.Present();
        // Frame limiter: sleep for a little bit to not eat 100% of CPU
        SDL_Delay(1);  // esto se va luego, lo actualiza desde el server

        // ---------------------------- Draw PISTOLA ----------------------------
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
