#include "drawer_weapon.h"

#define WEAPON_INITIAL_X 1
#define WEAPON_INITIAL_Y 47

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE_WEAPON 10

DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer, const sprite_t& weapon):
        texture(renderer,
                weapon_properties[static_cast<TEXTURE_WEAPONS>(weapon.id_texture)].texturePath) {}

void DrawerWeapon::draw(SDL2pp::Renderer& renderer, const sprite_t& weapon) {
    auto& properties = weapon_properties[static_cast<TEXTURE_WEAPONS>(weapon.id_texture)];

    if (properties.width == 0 || properties.height == 0) {
        std::cout << "Handling PISTOLA_COWBOY (or unknown weapon without defined properties)"
                  << std::endl;
        return;
    }

    renderer.Copy(
            texture,
            SDL2pp::Rect(properties.src_x, properties.src_y, properties.width, properties.height),
            SDL2pp::Rect(weapon.coordinate.get_x(), weapon.coordinate.get_y(), TILE_SIZE_WEAPON,
                         TILE_SIZE_WEAPON));
}
