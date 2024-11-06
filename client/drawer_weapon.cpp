#include "drawer_weapon.h"

#define WEAPON_INITIAL_X 1
#define WEAPON_INITIAL_Y 47

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE 50

DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer):
        texture(renderer, DATA_PATH "/DuckGame-Pistol.png"), x(0), y(0) {}

void DrawerWeapon::draw(SDL2pp::Renderer& renderer) {
    renderer.Copy(texture,
                  SDL2pp::Rect(WEAPON_INITIAL_X, WEAPON_INITIAL_Y, SIZE_WEAPON_SPRITE,
                               SIZE_WEAPON_SPRITE),
                  SDL2pp::Rect(this->x, this->y, TILE_SIZE, TILE_SIZE));
}

void DrawerWeapon::set_position(int x, int y) {
    this->x = x;
    this->y = y;
}
