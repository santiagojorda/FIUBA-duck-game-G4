#include "drawer_player.h"

#include <map>

#include "../../common/direction.h"
#include "../../common/weapons_id.h"
#include "../game_state/player.h"

#define TILE_SIZE_ALA 22
#define SIZE_DUCK_ALA 16
#define OFFSET_Y 12

/* Initial values */
#define SIZE_DUCK_SPRITE 32
#define DUCK_IDLE_X 1
#define DUCK_IDLE_Y 11

#define DUCK_SPRITE_CROUCHING_X 5
#define DUCK_SPRITE_CROUCHING_Y 1


DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& player):
        texture(renderer, textures[player.sprite.id_texture]), animations() {
    this->animations = AnimationLoader::load_animations(ANIMATION_PATH "/duck.yaml");
}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {
    bool flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    DuckStateType duck_state = static_cast<DuckStateType>(player.state);
    int duck_x = player.sprite.coordinate.get_x();
    int duck_y = player.sprite.coordinate.get_y();
    int frame = static_cast<int>(player.frame);
    std::cout << "player state: " << static_cast<int>(player.state) << "\n";
    int x = 0;
    int y = 0;

    switch (duck_state) {
        case DuckStateType::IS_IDLE:
            renderer.Copy(this->texture,
                          SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * 0),
                                       DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * 0), SIZE_DUCK_SPRITE,
                                       SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                          flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            break;
        case DuckStateType::IS_CROUCHING:
            renderer.Copy(this->texture,
                          SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * DUCK_SPRITE_CROUCHING_X),
                                       DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * DUCK_SPRITE_CROUCHING_Y),
                                       SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                          flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            break;
        case DuckStateType::IS_FALLING:

            break;
        case DuckStateType::IS_JUMPING:  // saltando
            std::cout << "frame: " << frame << "\n";

            if (frame == 6) {  // utilizo la primera fila
                x = DUCK_IDLE_X + (SIZE_DUCK_SPRITE * 0);
                y = DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * 0);
            } else {  // utilizo la segunda fila
                x = DUCK_IDLE_X + (SIZE_DUCK_SPRITE * frame);
                y = DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * 1);
            }
            renderer.Copy(this->texture, SDL2pp::Rect(x, y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                          flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            break;
        case DuckStateType::IS_DEAD:  // fila 3, col 1 y 2
            std::cout << "Muere "
                      << "\n";
            renderer.Copy(this->texture,
                          SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * frame),
                                       DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * 2), SIZE_DUCK_SPRITE,
                                       SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                          flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            break;
        case DuckStateType::IS_PLANNING:
            std::cout << "Planea "
                      << "\n";
            break;
        case DuckStateType::IS_RECOILING:
            std::cout << "recoiling? "
                      << "\n";
            break;
        case DuckStateType::IS_SLIPPING:  // fila 3, col 1
            renderer.Copy(this->texture,
                          SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * 0),
                                       DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * 2), SIZE_DUCK_SPRITE,
                                       SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                          flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            break;
        case DuckStateType::IS_RUNNING:
            std::cout << "frame: " << frame << "\n";
            renderer.Copy(this->texture,
                          SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * frame),
                                       DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * frame), SIZE_DUCK_SPRITE,
                                       SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                          flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            break;
        default:
            break;
    }
}
