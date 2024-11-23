#ifndef DRAWER_BOX_H
#define DRAWER_BOX_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../config/game_config.h"
#include "../game_state/elements.h"

class DrawerBox {
private:
    SDL2pp::Texture texture;

public:
    DrawerBox(SDL2pp::Renderer& renderer, const box_t& box);

    void draw(SDL2pp::Renderer& renderer, const box_t& box);
};

#endif  // DRAWER_BOX_H
