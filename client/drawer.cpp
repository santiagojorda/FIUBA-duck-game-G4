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

#define FACTOR_ZOOM 1

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
    Texture main_texture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH,
                         WINDOW_HEIGHT);
    main_texture.SetBlendMode(SDL_BLENDMODE_BLEND);

    // Por ahora tenemos 1 pato
    DrawerDuck drawer_duck(renderer);

    // Load background image as a new texture
    Texture background(renderer, DATA_PATH "/background.png");

    // Load tileset image as a new texture
    Texture floor(renderer, DATA_PATH "/NatureTileset.png");

    // Load pistol image as a new texture
    Texture pistol_magnum(renderer, DATA_PATH "/DuckGame-Pistol.png");

    // Load ala pato image as a new texture
    Texture ala_duck(renderer, DATA_PATH "/DuckGame-YellowDuck.png");

    // Game state
    bool is_running = false;
    bool is_moving_left = false;
    std::vector<PlayerPosition_t> position;

    // SDL_Event event_init;
    //  Se envia la tecla que presionó el usuario

    // keyboard_controller.procesar_comando(event_init, is_running, is_moving_left);

    while (true) {  // receiver del cliente
        // position = positions.pop();

        while (positions.try_pop(position)) {

            // Cambiamos el render target a main_texture
            SDL_SetRenderTarget(renderer.Get(), main_texture.Get());

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


            // ---------------------------- Draw Pato ----------------------------
            for (const auto& pos: position) {
                drawer_duck.set_position(pos.coordinate.get_x(), pos.coordinate.get_y());
                drawer_duck.set_is_moving_left(is_moving_left);
                drawer_duck.update_animation(is_running);
                drawer_duck.draw(renderer);
            }

            // Cambiar el render target de vuelta a la pantalla
            SDL_SetRenderTarget(renderer.Get(), nullptr);

            // Calcular el tamaño de destino para zoom
            int dest_width = WINDOW_WIDTH * FACTOR_ZOOM;  // Ajusta el factor de zoom como prefieras
            int dest_height = WINDOW_HEIGHT * FACTOR_ZOOM;

            int dest_x = 0, dest_y = 0;
            if (FACTOR_ZOOM != 1.0) {
                // calculamos dest_x y dest_y basados en la posición del pato
                // Si el factor de zoom no es 1, centramos el zoom en la posición del pato
                // si no hago esto:el zoom podría aparecer desplazado o desalineado respecto al pato
                // tomamos la posición del pato para centrar el zoom en este
                int duck_x = position[0].coordinate.get_x();
                int duck_y = position[0].coordinate.get_y();

                dest_x = WINDOW_WIDTH / 2 - (duck_x * FACTOR_ZOOM);
                dest_y = WINDOW_HEIGHT / 2 - (duck_y * FACTOR_ZOOM);
            }

            renderer.Clear();
            renderer.Copy(main_texture, SDL2pp::NullOpt,
                          Rect(dest_x, dest_y, dest_width, dest_height));
            renderer.Present();
        }

        SDL_Event event;
        // Se envia la tecla que presionó el usuario
        keyboard_controller.procesar_comando(event, is_running, is_moving_left);
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
