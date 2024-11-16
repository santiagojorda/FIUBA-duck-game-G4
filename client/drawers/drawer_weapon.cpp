#include "drawer_weapon.h"

#define WEAPON_INITIAL_X 1
#define WEAPON_INITIAL_Y 47

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE 50

/*

// DuckGame-Grenades.png ->  granadas, banana
// DuckGame-Laser.png -> pew pew laser
// DuckGame-MachineGuns.png ->  AK_47
// DuckGame-Pistol.png ->  pistola cowboy, magnum, supongo que la pistol es la pistola de duelos
// DuckGame-MoreWeapons.png -> sniper,
*/

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

DrawerWeapon::DrawerWeapon(sprite_t _weapon, SDL2pp::Renderer& renderer):
        weapon(_weapon),
        texture(renderer, textures[static_cast<TEXTURE_WEAPONS>(weapon.id_texture)]) {}

void DrawerWeapon::draw(SDL2pp::Renderer& renderer) {
    // TODO: tengo el path pero tengo que acceder a la posicion inicial de cada weapon, no todas
    // están posicionadas en un mismo lugar armar un map que tenga asociado los valores iniciales,
    // lo dejo hardcodeado por ahora

    renderer.Copy(texture,
                  SDL2pp::Rect(WEAPON_INITIAL_X, WEAPON_INITIAL_Y, SIZE_WEAPON_SPRITE,
                               SIZE_WEAPON_SPRITE),
                  SDL2pp::Rect(weapon.coordinate.get_x(), weapon.coordinate.get_y(), TILE_SIZE,
                               TILE_SIZE));
}

void DrawerWeapon::update_weapon(const sprite_t& update_weapon) { weapon = update_weapon; }
