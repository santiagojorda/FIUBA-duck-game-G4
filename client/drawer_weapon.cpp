#include "drawer_weapon.h"

DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer):
        texture(renderer, DATA_PATH "/DuckGame-Pistol.png"), x(0), y(0) {}

void DrawerWeapon::set_position(int new_x, int new_y) {
    this->x = new_x;
    this->y = new_y;
}
