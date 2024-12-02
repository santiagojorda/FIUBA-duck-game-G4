#include "drawer.h"

#include "../../common/sleep_special.h"

using namespace SDL2pp;

Drawer::Drawer(Queue<ClientEvent_t>& commands, Queue<client_game_state_t>& game_state):
        commands(commands),
        game_state(game_state),
        keyboard_controller(commands, 2),
        drawers(),
        animations(),
        actual_game_state(),
        window(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
               WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE),
        renderer(window, -1, SDL_RENDERER_ACCELERATED) {}

void Drawer::run() try {
    SDL sdl(SDL_INIT_VIDEO);

    Texture main_texture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH,
                         WINDOW_HEIGHT);

    main_texture.SetBlendMode(SDL_BLENDMODE_BLEND);

    Texture background(renderer, DATA_PATH "/background.png");

    SleepSpecial sleep(MILISECONDS_30_FPS);
    int iteration = 0;

    ZoomHandler zoom_handler;
    //  Cargar resources, incluir musica
    load_resources();
    static std::map<std::string, Animation> empty_animations;

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
        this->renderer.Clear();

        this->renderer.Copy(background, Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

        SDL_SetRenderTarget(renderer.Get(), main_texture.Get());

        this->renderer.SetDrawColor(0, 0, 0, 0);

        this->renderer.Clear();

        load_floor();
        load_ducks();
        // load_boxes();
        // load_bullets();
        // load_weapons();

        SDL_SetRenderTarget(this->renderer.Get(), nullptr);

        if (actual_game_state.players.size() > 0) {
            zoom_handler.calculate_zoom(actual_game_state.players);
            zoom_handler.apply_zoom(this->renderer, main_texture);
        }

        this->renderer.Present();

        sleep.sleep_rate(iteration);
        SDL_Event event;
        keyboard_controller.procesar_comando(event);
    }

    clean_elements();
} catch (std::exception& e) {
    clean_elements();
    std::cerr << e.what() << std::endl;
}

void Drawer::load_ducks() {
    if (actual_game_state.players.size() != drawers.players.size()) {
        for (auto& player: drawers.players) {
            delete player;
        }

        drawers.players.clear();

        drawers.players.resize(actual_game_state.players.size());

        for (size_t i = 0; i < actual_game_state.players.size(); i++) {
            auto player = actual_game_state.players[i];
            DrawerPlayer* new_player = new DrawerPlayer(
                    this->renderer, player.sprite.id_texture, this->animations.animation_duck,
                    this->animations.animation_weapon, this->animations.animation_armor);
            drawers.players[i] = new_player;
        }
    }


    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        player_t player = actual_game_state.players[i];
        drawers.players[i]->draw(player);
    }
}

void Drawer::load_floor() {
    // Draw Floor
    if (drawers.floors.size() != actual_game_state.floors.size()) {
        drawers.floors.resize(actual_game_state.floors.size());

        for (size_t i = 0; i < actual_game_state.floors.size(); ++i) {
            if (!drawers.floors[i]) {
                auto floor = actual_game_state.floors[i];
                DrawerFloor* drawer_floor = new DrawerFloor(this->renderer, floor.path);
                // drawers.floors[i] = std::make_unique<DrawerFloor>(renderer, floor.path);
                drawers.floors[i] = drawer_floor;
            }
        }
    }

    for (size_t i = 0; i < actual_game_state.floors.size(); ++i) {
        auto floor = actual_game_state.floors[i];
        drawers.floors[i]->draw(floor);
    }
}

void Drawer::load_weapons() {
    if (drawers.weapons.size() != actual_game_state.weapons.size()) {
        for (auto& weapon: drawers.weapons) {
            delete weapon;
        }
        drawers.weapons.clear();
        drawers.weapons.resize(actual_game_state.weapons.size());

        for (size_t i = 0; i < actual_game_state.weapons.size(); ++i) {
            if (!drawers.weapons[i]) {
                auto weapon = actual_game_state.weapons[i];
                DrawerWeapon* drawer_weapon = new DrawerWeapon(
                        this->renderer, weapon.sprite.id_texture, animations.animation_weapon);
                drawers.weapons[i] = drawer_weapon;
            }
        }
    }

    for (size_t i = 0; i < actual_game_state.weapons.size(); ++i) {
        auto weapon = actual_game_state.weapons[i];
        drawers.weapons[i]->draw(weapon.sprite.coordinate);
    }
}

void Drawer::load_boxes() {
    // Draw Box
    if (drawers.boxes.size() != actual_game_state.boxs.size()) {
        drawers.boxes.resize(actual_game_state.boxs.size());
        for (size_t i = 0; i < actual_game_state.boxs.size(); ++i) {
            if (!drawers.boxes[i]) {
                auto box = actual_game_state.boxs[i];
                DrawerBox* drawer_box = new DrawerBox(this->renderer, box);
                drawers.boxes[i] = drawer_box;
                // drawers.boxes[i] = std::make_unique<DrawerBox>(renderer, box);
            }
        }
    }

    for (size_t i = 0; i < actual_game_state.boxs.size(); ++i) {
        auto box = actual_game_state.boxs[i];
        drawers.boxes[i]->draw(this->renderer, box);
    }
}

void Drawer::load_bullets() {
    // Draw Bullet
    if (drawers.bullets.size() != actual_game_state.bullets.size()) {
        drawers.bullets.resize(actual_game_state.bullets.size());
        for (size_t i = 0; i < actual_game_state.bullets.size(); ++i) {
            if (!drawers.bullets[i]) {
                auto bullet = actual_game_state.bullets[i];
                DrawerBullet* drawer_bullet = new DrawerBullet(bullet, this->renderer);
                drawers.bullets[i] = drawer_bullet;
            }
        }
    }

    for (size_t i = 0; i < actual_game_state.bullets.size(); ++i) {
        auto bullet = actual_game_state.bullets[i];
        drawers.bullets[i]->update_bullet(bullet);
        drawers.bullets[i]->draw(this->renderer);
    }
}

void Drawer::clean_elements() {
    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        delete drawers.players[i];
    }

    for (size_t i = 0; i < actual_game_state.floors.size(); i++) {
        delete drawers.floors[i];
    }
    /*
    for (size_t i = 0; i < actual_game_state.weapons.size(); i++) {
        delete drawers.weapons[i];
    }

    for (size_t i = 0; i < actual_game_state.boxs.size(); i++) {
        delete drawers.boxes[i];
    }

    for (size_t i = 0; i < actual_game_state.bullets.size(); i++) {
        delete drawers.bullets[i];
    }*/
}

void Drawer::init_scenery(const client_game_state_t& actual_game_state) {
    if (actual_game_state.players.size() == drawers.players.size()) {
        return;
    }

    drawers.players.resize(actual_game_state.players.size());

    for (size_t i = 0; i < actual_game_state.players.size(); i++) {
        auto player = actual_game_state.players[i];

        DrawerPlayer* new_player = new DrawerPlayer(
                this->renderer, player.sprite.id_texture, this->animations.animation_duck,
                this->animations.animation_weapon, this->animations.animation_armor);

        std::cout << "player.sprite.id_texture o sea id pato: " << player.sprite.id_texture << "\n";
        drawers.players[i] = new_player;

        /*
                drawers.players[player.sprite.id_texture] = std::make_unique<DrawerPlayer>(
                        this->renderer, player.sprite.id_texture, this->animations.animation_duck,
                        this->animations.animation_weapon, this->animations.animation_armor);
                drawers.players[player.sprite.id_texture]->draw(player);*/
    }
}


void Drawer::load_resources() {
    // es el dueño para que cargue las animaciones 1 sola vez.
    AnimationLoader::load_animations(ANIMATION_PATH "/duck.yaml", animations.animation_duck);
    AnimationLoader::load_animations(ANIMATION_PATH "/weapon.yaml", animations.animation_weapon);
    AnimationLoader::load_animations(ANIMATION_PATH "/armor.yaml", animations.animation_armor);
}
