#ifndef DRAWER_BOX_H
#define DRAWER_BOX_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/action_commands.h"
#include "../config/game_config.h"
#include "../game_state/elements.h"

class DrawerBox {
private:
    box_t box;
    SDL2pp::Texture texture;

public:
    DrawerBox(box_t _box, SDL2pp::Renderer& renderer);

    void draw(SDL2pp::Renderer& renderer);

    void update_box(const box_t& update_box);
};

#endif  // DRAWER_BOX_H
