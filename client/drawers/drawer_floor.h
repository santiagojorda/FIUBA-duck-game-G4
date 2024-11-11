#ifndef DRAWER_FLOOR_H
#define DRAWER_FLOOR_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../game_state/sprite.h"

#include "drawable.h"

class DrawerFloor {
private:
    sprite_t floor;
    SDL2pp::Texture texture;

public:
    DrawerFloor(sprite_t floor, SDL2pp::Renderer& renderer);
    void draw(SDL2pp::Renderer& renderer);

    void update_floor(const sprite_t& update_floor);
};

#endif  // DRAWER_FLOOR_H
