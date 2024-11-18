#ifndef DRAWER_WEAPON_H
#define DRAWER_WEAPON_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../game_state/sprite.h"

#include "drawable.h"
#include "weapon_properties.h"

class DrawerWeapon {
private:
    SDL2pp::Texture texture;

public:
    DrawerWeapon(SDL2pp::Renderer& renderer, const sprite_t& weapon);
    void draw(SDL2pp::Renderer& renderer, const sprite_t& weapon);
};

#endif  // DRAWER_WEAPON_H
