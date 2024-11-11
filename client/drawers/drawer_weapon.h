#ifndef DRAWER_WEAPON_H
#define DRAWER_WEAPON_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "drawable.h"
#include "../../common/weapons_id.h"
#include "../game_state/sprite.h"

class DrawerWeapon {
private:
    sprite_t weapon;
    SDL2pp::Texture texture;

public:
    DrawerWeapon(sprite_t weapon, SDL2pp::Renderer& renderer);
    void draw(SDL2pp::Renderer& renderer);
};

#endif  // DRAWER_WEAPON_H
