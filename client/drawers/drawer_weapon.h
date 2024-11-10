#ifndef DRAWER_WEAPON_H
#define DRAWER_WEAPON_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "drawable.h"

class DrawerWeapon {
private:
    SDL2pp::Texture texture;
    int x;
    int y;

public:
    DrawerWeapon(SDL2pp::Renderer& renderer);
    void draw(SDL2pp::Renderer& renderer);
    void set_position(int x, int y);
};

#endif  // DRAWER_WEAPON_H
