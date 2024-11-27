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

enum class TextureDucks {
    DUCK_YELLOW,
    DUCK_GREY,
    DUCK_ORANGE,
    DUCK_WHITE,
};

enum class InventoryDuck {
    HAS_ARMOR = 1,
    HAS_HELMET = 1,
};

static std::map<TextureDucks, std::string> textures_ducks = {
        {TextureDucks::DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
        {TextureDucks::DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
        {TextureDucks::DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
        {TextureDucks::DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}};

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


static std::map<InventoryDuck, std::string> textures_equipment_ducks = {
        {InventoryDuck::HAS_ARMOR, "has_armor"},
        {InventoryDuck::HAS_HELMET, "has_helmet"},
};

#endif  // TEXTURES_H
