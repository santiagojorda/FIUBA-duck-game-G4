#include "drawer_bullet.h"

#define SIZE_BULLET_SPRITE 16

// BALAS

enum TEXTURE_BULLET { BULLET_1 };

static std::map<TEXTURE_BULLET, std::string> textures = {{BULLET_1, DATA_PATH "/bala.png"}};

DrawerBullet::DrawerBullet(bullet_t _bullet, SDL2pp::Renderer& renderer):
        bullet(_bullet),
        texture(renderer, textures[static_cast<TEXTURE_BULLET>(bullet.bullet.id_texture)]) {}

void DrawerBullet::draw(SDL2pp::Renderer& renderer) {
    renderer.Copy(texture, SDL2pp::Rect(0, 0, 8, 8),
                  SDL2pp::Rect(bullet.bullet.coordinate.get_x(), bullet.bullet.coordinate.get_y(),
                               10, 10));
}

void DrawerBullet::update_bullet(const bullet_t& update_bullet) { bullet = update_bullet; }
