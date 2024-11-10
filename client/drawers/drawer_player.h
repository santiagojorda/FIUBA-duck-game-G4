#ifndef DRAWER_PLAYER_H
#define DRAWER_PLAYER_H

#include <chrono>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../game_state/player.h"

class DrawerPlayer {
private:
    player_t player;
    SDL2pp::Texture texture;

public:
    DrawerPlayer(player_t _player, SDL2pp::Renderer& renderer);
    void draw(SDL2pp::Renderer& renderer);
};

#endif  // DRAWER_PLAYER_H
