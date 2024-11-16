#ifndef DRAWER_FLOOR_H
#define DRAWER_FLOOR_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../config/game_config.h"
#include "../game_state/sprite.h"

#include "drawable.h"

class DrawerFloor {
private:
    SDL2pp::Texture texture;

public:
    DrawerFloor(SDL2pp::Renderer& renderer, sprite_t& floor);

    void draw(SDL2pp::Renderer& renderer, sprite_t& floor);
};

#endif  // DRAWER_FLOOR_H
