#include "drawer_weapon.h"

#include "../../common/weapons_id.h"

#define UNIQUE_FRAME 0

DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer, uint8_t texture_id,
                           std::map<std::string, AnimationWeapon>& animations):
        Drawable<AnimationWeapon>(renderer, animations), type_weapon("") {
    this->type_weapon = textures_weapons[static_cast<WeaponTextureID>(texture_id)];
    std::string texture_weapon = this->animations[this->type_weapon].get_path();
    this->texture = std::make_unique<SDL2pp::Texture>(renderer, DATA_PATH + texture_weapon);
}

void DrawerWeapon::draw(const sprite_t& weapon) {
    this->coordenada_x = weapon.coordinate.get_x();
    this->coordenada_y = weapon.coordinate.get_y();
    this->scale_width = TILE_SIZE_WEAPON;
    this->scale_height = TILE_SIZE_WEAPON;
    auto anim = this->animations[this->type_weapon].get_current_frame(UNIQUE_FRAME);
    render(anim);
}

void DrawerWeapon::draw_with_coordinates(const Coordinate& coordinate, uint8_t is_looking) {
    auto [offset_right_x, offset_left_x, offset_y, _scale_width, _scale_height] =
            this->animations[this->type_weapon].get_render_config();
    this->flip = static_cast<Direction>(is_looking) == Direction::LEFT;
    this->coordenada_x =
            this->flip ? coordinate.get_x() + offset_left_x : coordinate.get_x() + offset_right_x;
    this->coordenada_y = coordinate.get_y() + offset_y - OFFSET_Y_DUCK;
    this->scale_width = _scale_width;
    this->scale_height = _scale_height;
    auto anim = this->animations[this->type_weapon].get_current_frame(UNIQUE_FRAME);
    render(anim);
}
