#include "drawer_floor.h"

#define TILE_SIZE 50

#define SIZE_FLOOR_SPRITE 16

enum TEXTURE_FLOOR { FLOOR_1 };

static std::map<TEXTURE_FLOOR, std::string> textures = {{FLOOR_1, DATA_PATH "/NatureTileset.png"}};


DrawerFloor::DrawerFloor(sprite_t _floor, SDL2pp::Renderer& renderer):
        floor(_floor), texture(renderer, textures[static_cast<TEXTURE_FLOOR>(floor.id_texture)]) {}

void DrawerFloor::draw(SDL2pp::Renderer& renderer) {
    int src_x = SIZE_FLOOR_SPRITE * 3;
    int src_y = 0;

    renderer.Copy(
            texture, SDL2pp::Rect(src_x, src_y, SIZE_FLOOR_SPRITE, SIZE_FLOOR_SPRITE),
            SDL2pp::Rect(floor.coordinate.get_x(), floor.coordinate.get_y(), TILE_SIZE, TILE_SIZE));
}

void DrawerFloor::update_floor(const sprite_t& update_floor) { floor = update_floor; }
