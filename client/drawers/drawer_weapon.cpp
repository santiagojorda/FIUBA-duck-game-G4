#include "drawer_weapon.h"

#define WEAPON_INITIAL_X 1
#define WEAPON_INITIAL_Y 47

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE 50

static std::map<TEXTURE_WEAPONS, WeaponProperties> weaponProperties = {
        {GRANADA, {"DATA_PATH/DuckGame-Grenades.png", 1, 21, 15, 15}},
        {BANANA, {"DATA_PATH/DuckGame-Grenades.png", 1, 51, 15, 15}},
        {PEW_PEW_LASER, {"DATA_PATH/DuckGame-Laser.png", 336, 94, 32, 32}},
        {LASER_RIFLE, {"DATA_PATH/DuckGame-Laser.png", 1, 97, 32, 32}},
        {AK_47, {"DATA_PATH/DuckGame-MachineGuns.png", 1, 19, 32, 32}},
        {PISTOLA_DUELOS, {"DATA_PATH/DuckGame-Pistol.png", 35, 68, 18, 10}},
        {PISTOLA_COWBOY, {"DATA_PATH/DuckGame-Pistol.png", 0, 0, 0, 0}},  // Sin coordenadas, me falta encontrar esta :(
        {MAGNUM, {"DATA_PATH/DuckGame-Pistol.png", 1, 47, 32, 32}},
        {ESCOPETA, {"DATA_PATH/DuckGame-Props.png", 60, 114, 41, 11}},
        {SNIPER, {"DATA_PATH/DuckGame-MoreWeapons.png", 36, 237, 33, 9}}};

DrawerWeapon::DrawerWeapon(sprite_t _weapon, SDL2pp::Renderer& renderer):
        weapon(_weapon),
        texture(renderer,
                weaponProperties[static_cast<TEXTURE_WEAPONS>(weapon.id_texture)].texturePath) {}

void DrawerWeapon::draw(SDL2pp::Renderer& renderer) {
    auto& properties = weaponProperties[static_cast<TEXTURE_WEAPONS>(weapon.id_texture)];

    if (properties.width == 0 || properties.height == 0) {
        std::cout << "Handling PISTOLA_COWBOY (or unknown weapon without defined properties)"
                  << std::endl;
        return;
    }

    renderer.Copy(
            texture,
            SDL2pp::Rect(properties.src_x, properties.src_y, properties.width, properties.height),
            SDL2pp::Rect(weapon.coordinate.get_x(), weapon.coordinate.get_y(), TILE_SIZE,
                         TILE_SIZE));
}

void DrawerWeapon::update_weapon(const sprite_t& update_weapon) { weapon = update_weapon; }
