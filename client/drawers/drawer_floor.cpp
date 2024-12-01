#include "drawer_floor.h"

#define SIZE_FLOOR_SPRITE 16

enum TEXTURE_FLOOR { FLOOR_1 };

static std::map<TEXTURE_FLOOR, std::string> textures = {{FLOOR_1, DATA_PATH "/NatureTileset.png"}};

DrawerFloor::DrawerFloor(SDL2pp::Renderer& renderer, const floor_sprite_t& floor):
        texture(renderer, textures[static_cast<TEXTURE_FLOOR>(floor.path)]) {}

void DrawerFloor::draw(SDL2pp::Renderer& renderer, const floor_sprite_t& floor) {
    // Por ahora lo dejo hardcodeado. En el floor necesito el sprite asociado
    // si es una piedra, si es un fin , un inicio, etc.
    int src_x = SIZE_FLOOR_SPRITE * 3;
    int src_y = 0;

    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_FLOOR_SPRITE, SIZE_FLOOR_SPRITE),
                  SDL2pp::Rect(floor.coordinate.get_x(), floor.coordinate.get_y(),
                               SIZE_FLOOR_SPRITE, SIZE_FLOOR_SPRITE));
}
