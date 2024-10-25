#include "drawer.h"

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

using namespace SDL2pp;

Drawer::Drawer() {}

void Drawer::run() try {
    SDL sdl(SDL_INIT_VIDEO);

    Window window("DuckGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                  SDL_WINDOW_RESIZABLE);

    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load sprites image as a new texture
    Texture sprites(renderer, DATA_PATH "/DuckGame-YellowDuck.png");

    // Load background image as a new texture
    Texture background(renderer, DATA_PATH "/background.png");

    // Load tileset image as a new texture
    Texture floor(renderer, DATA_PATH "/NatureTileset.png");

    int x_principal = 1;

    // Game state
    bool is_running = false;
    bool is_moving_left = false;

    int run_phase = -1;    // run animation phase
    float position = 0.0;  // player position

    unsigned int prev_ticks = SDL_GetTicks();  // an unsigned 32-bit value representing the number
                                               // of milliseconds since the SDL library initialized.

    // Recibe game state

    // Main loop
    while (true) {  // receiver del cliente
        // Timing: calculate difference between this and previous frame
        // in milliseconds
        unsigned int frame_ticks = SDL_GetTicks();
        unsigned int frame_delta = frame_ticks - prev_ticks;
        prev_ticks = frame_ticks;

        // Event processing:
        // - If window is closed, or Q or Escape buttons are pressed,
        //   quit the application
        // - If Right key is pressed, character would run
        // - If Right key is released, character would stop
        SDL_Event event;
        while (SDL_PollEvent(&event)) { // este es un Sender :)
            if (event.type == SDL_QUIT) {
                return;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        return;
                    case SDLK_RIGHT:
                        is_running = true;
                        is_moving_left = false;
                        break;
                    case SDLK_LEFT:
                        is_running = true;
                        is_moving_left = true;
                        break;
                }
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

        // Update game state for this frame:
        // if character is runnung, move it to the right

        if (is_running) {
            if (is_moving_left) {
                position -= frame_delta *
                            0.2;  // move left si aumento el porcentaje, aumenta la velocidad
            } else {
                position += frame_delta * 0.2;  // move right
            }
            run_phase = (frame_ticks / 100) % 6;  // animation phase. frame_ticks es la posicion
                                                  // actual dividido la cantidad de imagenes
        } else {
            run_phase = 0;
        }

        // If player passes past the right or left side of the window, wrap
        if (position > renderer.GetOutputWidth()) {
            position = -50;  // wrap from the right
        } else if (position < -50) {
            position = renderer.GetOutputWidth();  // wrap from the left
        }

        int vcenter = renderer.GetOutputHeight() / 2;  // Y coordinate of window center

        // Clear screen
        renderer.Clear();

        // Draw background
        renderer.Copy(background, Rect(0, 0, renderer.GetOutputWidth(),
                                       renderer.GetOutputHeight())  // full window background
        );

        int tile_size = 50;  // Size of the tile in pixels after scaling
        int num_tiles_x =
                renderer.GetOutputWidth() / tile_size + 1;  // Number of tiles needed horizontally

        for (int i = 0; i < num_tiles_x; ++i) {
            renderer.Copy(floor,
                          Rect(16 * 3, 0, 16, 16),  // source tile from the tileset. tamaño 16 x 16
                          Rect(i * tile_size, vcenter - (50 - 42), tile_size, tile_size));
        }


        // Pick sprite from sprite atlas based on whether
        // player is running and run animation phase
        int src_x = x_principal, src_y = 11;  // by default, standing sprite
        if (is_running) {
            src_x = x_principal + 32 * run_phase;
            src_y = 11;
        }

        // Flip the sprite if moving left
        SDL_RendererFlip flip = is_moving_left ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

        // Draw player sprite
        renderer.Copy(sprites,
                      Rect(src_x, src_y, 32, 32),  // (x, y, w, h): (x, y) toman una coordenada de
                                                   // la imagen (w, h) le indicamos el alto y ancho
                      Rect((int)position, vcenter - 50, 50,
                           50),  // le indicamos en que parte de la pantalla aparece, y el tamaño
                      0.0,       // no rotation
                      SDL2pp::NullOpt,  // no center for rotation
                      flip              // flip horizontally if moving left
        );

        renderer.Present();
        // Frame limiter: sleep for a little bit to not eat 100% of CPU
        SDL_Delay(1);  // esto se va luego, lo actualiza desde el server
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
