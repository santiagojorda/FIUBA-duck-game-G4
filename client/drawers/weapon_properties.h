#ifndef WEAPON_PROPERTIES_H
#define WEAPON_PROPERTIES_H

#include <map>

struct weapon_properties_t {
    std::string texturePath;
    int src_x;
    int src_y;
    int width;
    int height;
};

static std::map<TEXTURE_WEAPONS, weapon_properties_t> weapon_properties = {
        {GRANADA_ID, {DATA_PATH "/DuckGame-Grenades.png", 1, 21, 15, 15}},
        {BANANA_ID, {DATA_PATH "/DuckGame-Grenades.png", 1, 51, 15, 15}},
        {PEW_PEW_LASER_ID, {DATA_PATH "/DuckGame-Laser.png", 336, 94, 32, 32}},
        {LASER_RIFLE_ID, {DATA_PATH "/DuckGame-Laser.png", 1, 97, 32, 32}},
        {AK_47_ID, {DATA_PATH "/DuckGame-MachineGuns.png", 1, 19, 32, 32}},
        {PISTOLA_DUELOS_ID, {DATA_PATH "/DuckGame-Pistol.png", 35, 68, 18, 10}},
        {PISTOLA_COWBOY_ID,
         {DATA_PATH "/DuckGame-Pistol.png", 0, 0, 0,
          0}},  // Sin coordenadas, me falta encontrar esta :(
        {MAGNUM_ID, {DATA_PATH "/DuckGame-Pistol.png", 1, 47, 32, 32}},
        {ESCOPETA_ID, {DATA_PATH "/DuckGame-Props.png", 60, 114, 41, 11}},
        {SNIPER_ID, {DATA_PATH "/DuckGame-MoreWeapons.png", 36, 237, 33, 9}}};


#endif  // WEAPON_PROPERTIES_H
