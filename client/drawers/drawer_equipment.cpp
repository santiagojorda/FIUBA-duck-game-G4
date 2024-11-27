#include "drawer_equipment.h"

DrawerEquipment::DrawerEquipment(SDL2pp::Renderer& renderer, uint8_t texture_id,
                                 std::map<std::string, AnimationWeapon>& animations):
        Drawable<AnimationWeapon>(renderer, animations) {

    std::string type = textures_equipment_ducks[static_cast<InventoryDuck>(texture_id)];
    std::string texture_armor = this->animations[type].get_path();
    this->texture = std::make_unique<SDL2pp::Texture>(renderer, DATA_PATH + texture_armor);
}

void DrawerEquipment::draw(const player_t& player, const std::string& type_animation) {
    auto [offset_right_x, offset_left_x, offset_y, _scale_width, _scale_height] =
            this->animations[type_animation].get_render_config();
    this->flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    this->coordenada_x = this->flip ? player.sprite.coordinate.get_x() + offset_left_x :
                                      player.sprite.coordinate.get_x() + offset_right_x;
    this->coordenada_y = player.sprite.coordinate.get_y() + offset_y - OFFSET_Y_DUCK;
    this->scale_width = _scale_width;
    this->scale_height = _scale_height;
    this->frame = static_cast<int>(player.frame);
    update_animation(type_animation);
}

void DrawerEquipment::update_animation(const std::string& type_animation) {
    auto anim = this->animations[type_animation].get_current_frame(this->frame);
    render(anim);
}
