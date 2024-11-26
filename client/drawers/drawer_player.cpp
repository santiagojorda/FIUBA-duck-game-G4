#include "drawer_player.h"

#include <map>

#include "../../common/direction.h"
#include "../../common/weapons_id.h"
#include "../game_state/player.h"

#define TILE_SIZE_ALA 22

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id,
                           std::map<std::string, Animation>& _animations, uint8_t is_looking):
        Drawable<Animation>(
                renderer,
                std::make_unique<SDL2pp::Texture>(
                        renderer, textures_ducks[static_cast<TextureDucks>(texture_id)]),
                _animations, static_cast<Direction>(is_looking) == Direction::LEFT) {}

void DrawerPlayer::draw(const player_t& player, std::map<std::string, AnimationWeapon>& animation) {
    this->flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    this->coordenada_x = player.sprite.coordinate.get_x();
    this->coordenada_y = player.sprite.coordinate.get_y() - OFFSET_Y_DUCK;
    this->scale_height = TILE_SIZE;
    this->scale_width = TILE_SIZE;
    this->frame = static_cast<int>(player.frame);

    DuckStateType duck_state = static_cast<DuckStateType>(player.state);

    std::string type_action = textures_action_ducks.at(duck_state);
    if(duck_state == DuckStateType::DEAD){
        return;
    }
    this->update_animation(type_action);
    if (static_cast<int>(player.inventory.weapon) != 0) {
        this->update_weapon(player, animation);
        this->update_wings();
    }
    /*
        auto animation_armadura =
                AnimationLoader::load_animations<AnimationWeapon>(ANIMATION_PATH "/armadura.yaml");
        std::cout << animation_armadura["armor"].get_path() << "\n";
        SDL2pp::Texture weapon_texture(renderer, weapon_props.texturePath);

        auto [_offset_x, _offset_y, _scale_width, _scale_height] =
                animation_armadura["armor"].get_render_config();
        render(animation_armadura["armor"].get_current_frame(0));
    */
}

void DrawerPlayer::update_weapon(const player_t& player,
                                 std::map<std::string, AnimationWeapon>& animation_weapon) {
    DrawerWeapon drawer_weapon(this->renderer, player.inventory.weapon, animation_weapon);
    drawer_weapon.draw_with_coordinates(player.sprite.coordinate, player.is_looking);
}

void DrawerPlayer::update_wings() {
    this->scale_height = TILE_SIZE_ALA;
    this->scale_width = TILE_SIZE_ALA;
    this->coordenada_x += flip ? 16 : 12;
    this->coordenada_y += 15;
    auto anim = this->animations["wings_weapon"].get_current_frame(this->frame);
    render(anim);
}

void DrawerPlayer::update_animation(const std::string type_animation) {
    auto anim = this->animations[type_animation].get_current_frame(this->frame);
    render(anim);
}
