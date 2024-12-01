#include "drawer_weapon.h"

#include "../../common/weapons_id.h"

DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer, uint8_t texture_id,
                           std::map<std::string, Animation>& animations):
        Drawable(renderer, animations) {
    this->type_animation =
            texture_provider.get_weapon_texture(static_cast<WeaponTextureID>(texture_id));
    std::string path = this->animations[this->type_animation].get_path();
    this->texture = std::make_unique<SDL2pp::Texture>(renderer, DATA_PATH + path);
}

// TODO: agregarle un is_looking al arma que se muestra por pantalla tambien
void DrawerWeapon::draw(const Coordinate& coordinate) {
    // this->flip = static_cast<Direction>(is_looking) == Direction::LEFT;
    auto config = this->animations.at(this->type_animation).get_config_screen();
    this->coordenada_x = coordinate.get_x();
    this->coordenada_y = coordinate.get_y();
    this->scale_width = config.scale_width;
    this->scale_height = config.scale_height;
    this->render();
}

void DrawerWeapon::draw_inventory(const Coordinate& coordinate, uint8_t is_looking) {
    auto config = this->animations.at(this->type_animation).get_config_screen();
    this->flip = static_cast<Direction>(is_looking) == Direction::LEFT;
    this->scale_width = config.scale_width;
    this->scale_height = config.scale_height;
    this->coordenada_x = this->flip ? coordinate.get_x() + config.offset_left_x :
                                      coordinate.get_x() + config.offset_right_x;
    this->coordenada_y = coordinate.get_y() + config.offset_y - OFFSET_Y_DUCK;
    this->render();
}
