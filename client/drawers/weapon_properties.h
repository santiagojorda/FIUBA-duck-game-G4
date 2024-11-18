#ifndef WEAPON_PROPERTIES_H
#define WEAPON_PROPERTIES_H

#include <map>

#include "../../common/weapons_id.h"

#define SCALE_WEAPON 38  // PEW_PEW_LASER, LASER_RIFLE
#define SCALE_GRANADA 24

struct weapon_properties_t {
    std::string texturePath;
    int src_x;
    int src_y;
    int width;
    int height;
};

static std::map<WeaponTextureID, weapon_properties_t> weapon_properties = {
        {WeaponTextureID::GRANATE, {DATA_PATH "/DuckGame-Grenades.png", 1, 21, 15, 15}},
        {WeaponTextureID::BANANA, {DATA_PATH "/DuckGame-Grenades.png", 1, 51, 15, 15}},
        {WeaponTextureID::PEW_PEW_LASER, {DATA_PATH "/DuckGame-Laser.png", 336, 94, 32, 32}},
        {WeaponTextureID::LASER_RIFLE, {DATA_PATH "/DuckGame-Laser.png", 1, 97, 32, 32}},
        {WeaponTextureID::AK_47, {DATA_PATH "/DuckGame-MachineGuns.png", 1, 19, 32, 32}},
        {WeaponTextureID::DUELING_GUN, {DATA_PATH "/DuckGame-Pistol.png", 35, 68, 18, 10}},
        {WeaponTextureID::COWBOY_GUN, {DATA_PATH "/DuckGame-Pistol.png", 1, 20, 22, 11}},
        {WeaponTextureID::MAGNUM, {DATA_PATH "/DuckGame-Pistol.png", 1, 47, 32, 32}},
        {WeaponTextureID::SHOTGUN, {DATA_PATH "/DuckGame-MoreWeapons.png", 60, 114, 41, 11}},
        {WeaponTextureID::SNIPER, {DATA_PATH "/DuckGame-MoreWeapons.png", 36, 237, 33, 9}}};

class WeaponConfig {
public:
    int offset_x;
    int offset_y;
    int scale_width;
    int scale_height;

    WeaponConfig(WeaponTextureID weapon, bool is_facing_left, const Coordinate& coord) {
        if (weapon == WeaponTextureID::GRANATE) {
            offset_x = is_facing_left ? coord.get_x() + 5 : coord.get_x() + 20;
            offset_y = coord.get_y() + 10;
            scale_width = SCALE_GRANADA;
            scale_height = SCALE_GRANADA;
        } else if (weapon == WeaponTextureID::BANANA) {
            offset_x = is_facing_left ? coord.get_x() + 10 : coord.get_x() + 15;
            offset_y = coord.get_y() + 5;
            scale_width = SCALE_GRANADA;
            scale_height = SCALE_GRANADA;
        } else if (weapon == WeaponTextureID::DUELING_GUN) {
            offset_x = is_facing_left ? coord.get_x() + 5 : coord.get_x() + 15;
            offset_y = coord.get_y() + 17;
            scale_width = 25;
            scale_height = 17;
        } else if (weapon == WeaponTextureID::SHOTGUN) {
            offset_x = is_facing_left ? coord.get_x() - 5 : coord.get_x() + 15;
            offset_y = coord.get_y() + 17;
            scale_width = 43;
            scale_height = 13;
        } else if (weapon == WeaponTextureID::SNIPER) {
            offset_x = is_facing_left ? coord.get_x() : coord.get_x() + 15;
            offset_y = coord.get_y() + 17;
            scale_width = 35;
            scale_height = 11;
        } else if (weapon == WeaponTextureID::COWBOY_GUN) {
            offset_x = is_facing_left ? coord.get_x() + 6 : coord.get_x() + 17;
            offset_y = coord.get_y() + 17;
            scale_width = 27;
            scale_height = 16;
        } else {
            offset_x = is_facing_left ? coord.get_x() + 5 : coord.get_x() + 7;
            offset_y = coord.get_y() + 6;
            scale_width = SCALE_WEAPON;
            scale_height = SCALE_WEAPON;
        }
    }
};

#endif  // WEAPON_PROPERTIES_H
