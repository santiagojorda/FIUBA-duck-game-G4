#include "drawer_floor.h"

#define SIZE_FLOOR_SPRITE 16

DrawerFloor::DrawerFloor(SDL2pp::Renderer& renderer, uint8_t texture_id):
        Drawable(renderer, Drawable::empty_animations) {
    std::string path =
            this->texture_provider.get_textures_floor(static_cast<FloorTexture>(texture_id));
    auto texture_capturado = std::make_shared<SDL2pp::Texture>(renderer, path);
    this->set_texture(texture_capturado);
}

void DrawerFloor::draw(const floor_sprite_t& floor) {
    this->coordenada_x = floor.coordinate.get_x();
    this->coordenada_y = floor.coordinate.get_y();
    this->scale_height = SIZE_FLOOR_SPRITE;
    this->scale_width = SIZE_FLOOR_SPRITE;

    uint8_t column = (floor.id_sprite % 8) * SIZE_FLOOR_SPRITE;
    uint8_t row = (floor.id_sprite / 8) * SIZE_FLOOR_SPRITE;
    this->render_with_rect(column, row, SIZE_FLOOR_SPRITE, SIZE_FLOOR_SPRITE);
}
