#ifndef DRAWER_WEAPON_H
#define DRAWER_WEAPON_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/weapons_id.h"
#include "../game_state/sprite.h"

#include "drawable.h"
#include "weapon_properties.h"

class DrawerWeapon {
private:
    sprite_t weapon;
    SDL2pp::Texture texture;

public:
    DrawerWeapon(sprite_t weapon, SDL2pp::Renderer& renderer);
    void draw(SDL2pp::Renderer& renderer);

    void update_weapon(const sprite_t& update_weapon);
};

#endif  // DRAWER_WEAPON_H
