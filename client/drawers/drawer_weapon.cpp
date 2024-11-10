#include "drawer_weapon.h"

#define WEAPON_INITIAL_X 1
#define WEAPON_INITIAL_Y 47

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE 50

/*

enum TEXTURE_WEAPONS {
    GRANADA,
    BANANA,
    PEW_PEW_LASER,
    LASER_RIFLE,
    AK_47,
    PISTOLA_DUELOS,
    PISTOLA_COWBOY,
    MAGNUM,
    ESCOPETA,
    SNIPER
};

// DuckGame-Grenades.png ->  granadas, banana
// DuckGame-Laser.png -> pew pew laser
// DuckGame-MachineGuns.png ->  AK_47
// DuckGame-Pistol.png ->  pistola cowboy, magnum, supongo que la pistol es la pistola de duelos
// DuckGame-MoreWeapons.png -> sniper, 

static std::map<uint8_t, std::string> textures = {
    {GRANADA, DATA_PATH "/DuckGame-Grenades.png "}, // ok
    {BANANA, DATA_PATH "/DuckGame-Grenades.png "}, // ok
    {PEW_PEW_LASER, DATA_PATH "/DuckGame-Laser.png"}, // ok
    {LASER_RIFLE, DATA_PATH "/DuckGame-Laser.png"}, // ok
    {AK_47, DATA_PATH "/DuckGame-MachineGuns.png"}, // ok
    {PISTOLA_DUELOS, DATA_PATH "/DuckGame-Pistol.png"}, // ????????? supongo que es la pistol
    {PISTOLA_COWBOY, DATA_PATH "/DuckGame-Pistol.png"}, // ok
    {MAGNUM, DATA_PATH "/DuckGame-Pistol.png"}, // ok
    {ESCOPETA, DATA_PATH "/DuckGame-Props.png"},
    {SNIPER, DATA_PATH "/DuckGame-MoreWeapons.png"} // ok
};
*/
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
