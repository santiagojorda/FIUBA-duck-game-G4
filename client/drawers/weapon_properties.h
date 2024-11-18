#ifndef WEAPON_PROPERTIES_H
#define WEAPON_PROPERTIES_H

#include <map>
#include "../../common/weapons_id.h"

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
        {WeaponTextureID::COWBOY_GUN, {DATA_PATH "/DuckGame-Pistol.png", 0, 0, 0, 0}},  // Sin coordenadas, me falta encontrar esta :(
        {WeaponTextureID::MAGNUM, {DATA_PATH "/DuckGame-Pistol.png", 1, 47, 32, 32}},
        {WeaponTextureID::SHOTGUN, {DATA_PATH "/DuckGame-Props.png", 60, 114, 41, 11}},
        {WeaponTextureID::SNIPER, {DATA_PATH "/DuckGame-MoreWeapons.png", 36, 237, 33, 9}}};


#endif  // WEAPON_PROPERTIES_H
