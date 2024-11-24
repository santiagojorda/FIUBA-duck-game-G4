#ifndef TEXTURES_H
#define TEXTURES_H

#include <map>

#include "../../common/state_duck.h"
#include "../../common/weapons_id.h"
#include "../animation/animation_weapon.h"


static std::map<WeaponTextureID, std::string> textures_weapons = {
        {WeaponTextureID::GRANATE, "granate"},
        {WeaponTextureID::BANANA, "banana"},
        {WeaponTextureID::PEW_PEW_LASER, "pew_pew_laser"},
        {WeaponTextureID::LASER_RIFLE, "laser_rifle"},
        {WeaponTextureID::AK_47, "ak_47"},
        {WeaponTextureID::DUELING_GUN, "dueling_gun"},
        {WeaponTextureID::COWBOY_GUN, "cowboy_gun"},
        {WeaponTextureID::MAGNUM, "magnum"},
        {WeaponTextureID::SHOTGUN, "shotgun"},
        {WeaponTextureID::SNIPER, "sniper"}};

enum TEXTURE_DUCKS {
    DUCK_YELLOW,
    DUCK_GREY,
    DUCK_ORANGE,
    DUCK_WHITE,
};

static std::map<uint8_t, std::string> textures_ducks = {
        {DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
        {DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
        {DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
        {DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}};

static std::map<DuckStateType, std::string> textures_action_ducks = {
        {DuckStateType::JUMPING, "jumping"},
        {DuckStateType::RUNNING, "running"},
        {DuckStateType::CROUCHING, "crouching"},
        {DuckStateType::RECOILING, "recoiling"},
        {DuckStateType::FALLING, "falling"},
        {DuckStateType::SLIPPING, "slipping"},
        {DuckStateType::PLANNING, "planning"},
        {DuckStateType::IDLE, "idle"},
        {DuckStateType::DEAD, "dead"}};

#endif  // TEXTURES_H
