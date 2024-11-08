#include "drawer.h"

#include <chrono>

//FPS
#define MILISECONDS_30_FPS 33

// Game
#define GAME_TITLE "Duck Game"

// Window
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

// FLOOR
#define SIZE_FLOOR_SPRITE 16

// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling

// ALA DEL PATO en SPRITE -> las alas empiezan desde Y= 518, voy a suponer que miden 16x16
#define ALA_INITIAL_X 1
#define ALA_INITIAL_Y 518

#define FACTOR_ZOOM 1

using namespace SDL2pp;

Drawer::Drawer(Queue<ClientEvent_t>& commands, Queue<std::vector<PlayerPosition_t>>& game_state):
        commands(commands), game_state(game_state), keyboard_controller(commands, 1) {}

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

    // vector para manejar múltiples patos
    std::vector<std::shared_ptr<DrawerDuck>> drawer_ducks;


    std::vector<std::shared_ptr<DrawerWeapon>> drawer_weapons;

    // Inicializar DrawerWeapon y agregarlo al vector
    drawer_weapons.push_back(std::make_shared<DrawerWeapon>(renderer));


    // Load background image as a new texture
    Texture background(renderer, DATA_PATH "/background.png");

    // Load tileset image as a new texture
    Texture floor(renderer, DATA_PATH "/NatureTileset.png");

    // Load ala pato image as a new texture
    Texture ala_duck(renderer, DATA_PATH "/DuckGame-YellowDuck.png");

    ZoomHandler zoom_handler;

    // Game state
    bool is_running = false;
    bool is_moving_left = false;
    std::vector<PlayerPosition_t> position;

    // SDL_Event event_init;
    //  Se envia la tecla que presionó el usuario

    // keyboard_controller.procesar_comando(event_init, is_running, is_moving_left);

    auto chrono_now = std::chrono::high_resolution_clock::now(); 
    auto chrono_prev = chrono_now;

    while (true) {  // receiver del cliente

        while (game_state.try_pop(position)) { }

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
            // Llamar a set_position en DrawerWeapon
            drawer_weapons[0]->set_position(center_x, center_y - 41);
            drawer_weapons[0]->draw(renderer);

            // ---------------------------- Draw Patos ----------------------------
            if (drawer_ducks.size() != position.size()) {
                drawer_ducks.resize(position.size());
                for (size_t i = 0; i < position.size(); ++i) {
                    if (!drawer_ducks[i]) {
                        drawer_ducks[i] = std::make_shared<DrawerDuck>(renderer);
                    }
                }
            }

            for (size_t i = 0; i < position.size(); ++i) {
                int duck_x = position[i].coordinate.get_x();
                int duck_y = position[i].coordinate.get_y();
                drawer_ducks[i]->set_position(duck_x, duck_y);
                drawer_ducks[i]->set_is_moving_left(is_moving_left);
                drawer_ducks[i]->update_animation(is_running);
                drawer_ducks[i]->draw(renderer);
            }

            // Cambiar el render target de vuelta a la pantalla
            SDL_SetRenderTarget(renderer.Get(), nullptr);
            zoom_handler.calculate_zoom(position);
            renderer.Clear();
            // Aplicar zoom y centrar usando ZoomHandler
            zoom_handler.apply_zoom(renderer, main_texture);
            renderer.Present();
    
            chrono_now = std::chrono::high_resolution_clock::now();
            auto delta_chrono = (chrono_now - chrono_prev);
            if (delta_chrono <  std::chrono::milliseconds(MILISECONDS_30_FPS)) {
                std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS));
            }
            
        chrono_prev =  std::chrono::high_resolution_clock::now(); 

        SDL_Event event;
        // Se envia la tecla que presionó el usuario
        keyboard_controller.procesar_comando(event, is_running, is_moving_left);
    }

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
