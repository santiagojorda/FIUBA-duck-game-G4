#include "drawer_box.h"

DrawerBox::DrawerBox(SDL2pp::Renderer& renderer, uint8_t texture_id,
                     std::map<std::string, Animation>& animations):
        Drawable(renderer, animations) {
    this->type_animation = texture_provider.get_textures_box(static_cast<BoxTexture>(texture_id));
    std::string path = this->animations[this->type_animation].get_path();
    this->texture.emplace(renderer, DATA_PATH + path);
}

void DrawerBox::draw(const box_t& box) {
    auto config = this->animations.at(this->type_animation).get_config_screen();
    this->coordenada_x = box.box.coordinate.get_x();
    this->coordenada_y = box.box.coordinate.get_y();
    this->scale_width = config.scale_width;
    this->scale_height = config.scale_height;
    this->render();
}
