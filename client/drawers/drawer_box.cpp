#include "drawer_box.h"

#define BOX_INITIAL_X 1
#define BOX_INITIAL_Y 144

#define SIZE_BOX_SPRITE 16

enum TEXTURE_BOX { BOX };

static std::map<uint8_t, std::string> textures = {{BOX, DATA_PATH "/DuckGame-Props.png"}};

DrawerBox::DrawerBox(SDL2pp::Renderer& renderer, const box_t& box):
        texture(renderer, textures[box.box.id_texture]) {}

void DrawerBox::draw(SDL2pp::Renderer& renderer, const box_t& box) {
    int src_x = BOX_INITIAL_X;
    int src_y = BOX_INITIAL_Y;

    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_BOX_SPRITE, SIZE_BOX_SPRITE),
                  SDL2pp::Rect(box.box.coordinate.get_x(), box.box.coordinate.get_y(), TILE_SIZE,
                               TILE_SIZE));
}
