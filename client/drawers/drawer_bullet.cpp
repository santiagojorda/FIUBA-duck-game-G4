#include "drawer_bullet.h"

#define SIZE_BULLET_SPRITE 16
#define TILE_SIZE 50

enum TEXTURE_BULLET { BULLET_1 };

// TODO: update path
static std::map<TEXTURE_BULLET, std::string> textures = {
        {BULLET_1, DATA_PATH "/NatureTileset.png"}};

DrawerBullet::DrawerBullet(bullet_t _bullet, SDL2pp::Renderer& renderer):
        bullet(_bullet),
        texture(renderer, textures[static_cast<TEXTURE_BULLET>(bullet.bullet.id_texture)]) {}

void DrawerBullet::draw(SDL2pp::Renderer& renderer) {
    int src_x = 10;
    int src_y = 10;

    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_BULLET_SPRITE, SIZE_BULLET_SPRITE),
                  SDL2pp::Rect(bullet.bullet.coordinate.get_x(), bullet.bullet.coordinate.get_y(),
                               TILE_SIZE, TILE_SIZE));
}

void DrawerBullet::update_bullet(const bullet_t& update_bullet) { bullet = update_bullet; }
