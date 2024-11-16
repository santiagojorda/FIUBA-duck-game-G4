#ifndef DRAWER_PLAYER_H
#define DRAWER_PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/state_duck.h"
#include "../../common/weapons_id.h"
#include "../game_state/player.h"

#include "weapon_properties.h"

class DrawerPlayer {
private:
    SDL2pp::Texture texture;

public:
    DrawerPlayer(SDL2pp::Renderer& renderer, player_t& _player);

    void draw(SDL2pp::Renderer& renderer, player_t& _player);
};

#endif  // DRAWER_PLAYER_H
