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

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id, uint8_t is_looking):
        Drawable(renderer, static_cast<Direction>(is_looking) == Direction::LEFT) {
    this->texture = std::make_unique<SDL2pp::Texture>(renderer, textures[texture_id]);
    this->animations = AnimationLoader::load_animations(ANIMATION_PATH "/duck.yaml");
}

void DrawerPlayer::draw(const player_t& player) {
    this->flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    this->coordenada_x = player.sprite.coordinate.get_x();
    this->coordenada_y = player.sprite.coordinate.get_y();
    this->scale_height = TILE_SIZE;
    this->scale_width = TILE_SIZE;
    int frame = static_cast<int>(player.frame);

    DuckStateType duck_state = static_cast<DuckStateType>(player.state);

    switch (duck_state) {
        case DuckStateType::IS_IDLE:
            this->update_animation("idle", frame);
            break;
        case DuckStateType::IS_CROUCHING:
            this->update_animation("crouching", frame);
            break;
        case DuckStateType::IS_RUNNING:
            this->update_animation("running", frame);
            break;
        case DuckStateType::IS_JUMPING:
            this->update_animation("jumping", frame);
            break;
        case DuckStateType::IS_FALLING:
            this->update_animation("falling", frame);
            break;
        default:
            this->update_animation("idle", frame);
            break;
    }
}

void DrawerPlayer::update_animation(const std::string type_animation, int frame) {
    auto anim = this->animations[type_animation].get_current_frame(frame);
    render(anim);
}
