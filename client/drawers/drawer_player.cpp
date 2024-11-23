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

/*
DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, bool flip, uint8_t texture_id):
        Drawable(renderer, flip) {
    this->texture = Texture texture(renderer, textures[texture_id]);
    this->animations = AnimationLoader::load_animations(ANIMATION_PATH "/duck.yaml");
}*/

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id, bool flip)
        : Drawable(renderer, flip), texture(renderer, textures[texture_id]) {
        this->animations = AnimationLoader::load_animations(ANIMATION_PATH "/duck.yaml");
    }

void DrawerPlayer::draw(const player_t& player) {
    bool flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    DuckStateType duck_state = static_cast<DuckStateType>(player.state);
    int duck_x = player.sprite.coordinate.get_x();
    int duck_y = player.sprite.coordinate.get_y();
    int frame = static_cast<int>(player.frame) - 1;

    switch (duck_state) {
        case DuckStateType::IS_IDLE:
            this->update_animation("idle", frame, duck_x, duck_y, TILE_SIZE, TILE_SIZE);
            break;
        case DuckStateType::IS_CROUCHING:
            this->update_animation("crouching", frame, duck_x, duck_y, TILE_SIZE, TILE_SIZE);
            break;
        case DuckStateType::IS_RUNNING:
            this->update_animation("running", frame, duck_x, duck_y, TILE_SIZE, TILE_SIZE);
            break;
        default:
            break;
    }
}

void DrawerPlayer::update_animation(const std::string type_animation, int frame, int coor_x, int coor_y, int scale_w, int scale_h) {
    auto anim = this->animations[type_animation].get_current_frame(frame);
    render(anim, coor_x, coor_y, scale_w, scale_h);
}
