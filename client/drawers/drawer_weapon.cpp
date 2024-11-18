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

    static std::map<TEXTURE_WEAPONS, std::string> textures = {
            {GRANADA_ID, DATA_PATH "/DuckGame-Grenades.png "},    // ok
            {BANANA_ID, DATA_PATH "/DuckGame-Grenades.png "},     // ok
            {PEW_PEW_LASER_ID, DATA_PATH "/DuckGame-Laser.png"},  // ok
            {LASER_RIFLE_ID, DATA_PATH "/DuckGame-Laser.png"},    // ok
            {AK_47_ID, DATA_PATH "/DuckGame-MachineGuns.png"},    // ok
            {PISTOLA_DUELOS_ID,
             DATA_PATH "/DuckGame-Pistol.png"},  // ????????? supongo que es la pistol
            {PISTOLA_COWBOY_ID, DATA_PATH "/DuckGame-Pistol.png"},  // ok
            {MAGNUM_ID, DATA_PATH "/DuckGame-Pistol.png"},          // ok
            {ESCOPETA_ID, DATA_PATH "/DuckGame-Props.png"},
            {SNIPER_ID, DATA_PATH "/DuckGame-MoreWeapons.png"}  // ok
    };

    renderer.Copy(
            texture,
            SDL2pp::Rect(properties.src_x, properties.src_y, properties.width, properties.height),
            SDL2pp::Rect(weapon.coordinate.get_x(), weapon.coordinate.get_y(), TILE_SIZE_WEAPON,
                         TILE_SIZE_WEAPON));
}
