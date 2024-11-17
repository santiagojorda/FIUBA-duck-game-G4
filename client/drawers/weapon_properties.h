#ifndef WEAPON_PROPERTIES_H
#define WEAPON_PROPERTIES_H

#include <map>

#define SCALE_WEAPON 38  // PEW_PEW_LASER, LASER_RIFLE
#define SCALE_GRANADA 24

struct weapon_properties_t {
    std::string texturePath;
    int src_x;
    int src_y;
    int width;
    int height;
};

static std::map<TEXTURE_WEAPONS, weapon_properties_t> weapon_properties = {
        {GRANADA, {DATA_PATH "/DuckGame-Grenades.png", 1, 21, 15, 15}},
        {BANANA, {DATA_PATH "/DuckGame-Grenades.png", 1, 51, 15, 15}},
        {PEW_PEW_LASER, {DATA_PATH "/DuckGame-Laser.png", 336, 94, 32, 32}},
        {LASER_RIFLE, {DATA_PATH "/DuckGame-Laser.png", 1, 97, 32, 32}},
        {AK_47, {DATA_PATH "/DuckGame-MachineGuns.png", 1, 19, 32, 32}},
        {PISTOLA_DUELOS, {DATA_PATH "/DuckGame-Pistol.png", 35, 68, 18, 10}},
        {PISTOLA_COWBOY, {DATA_PATH "/DuckGame-Pistol.png", 0, 0, 0, 0}},
        {MAGNUM, {DATA_PATH "/DuckGame-Pistol.png", 1, 47, 32, 32}},
        {ESCOPETA, {DATA_PATH "/DuckGame-Props.png", 60, 114, 41, 11}},
        {SNIPER, {DATA_PATH "/DuckGame-MoreWeapons.png", 36, 237, 33, 9}}};

class WeaponConfig {
public:
    int offset_x;
    int offset_y;
    int scale_width;
    int scale_height;

    WeaponConfig(TEXTURE_WEAPONS weapon, bool is_facing_left, const Coordinate& coord) {
        if (weapon == GRANADA) {
            offset_x = is_facing_left ? coord.get_x() + 5 : coord.get_x() + 20;
            offset_y = coord.get_y() + 10;
            scale_width = SCALE_GRANADA;
            scale_height = SCALE_GRANADA;
        } else if (weapon == PISTOLA_DUELOS) {
            offset_x = is_facing_left ? coord.get_x() + 5 : coord.get_x() + 15;
            offset_y = coord.get_y() + 17;
            scale_width = 25;
            scale_height = 17;
        } else {
            offset_x = is_facing_left ? coord.get_x() + 5 : coord.get_x() + 7;
            offset_y = coord.get_y() + 6;
            scale_width = SCALE_WEAPON;
            scale_height = SCALE_WEAPON;
        }
    }
};

#endif  // WEAPON_PROPERTIES_H
