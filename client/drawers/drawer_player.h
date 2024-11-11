#ifndef DRAWER_PLAYER_H
#define DRAWER_PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../game_state/player.h"
#include "../../common/state_duck.h"

class DrawerPlayer {
private:
    player_t player;
    SDL2pp::Texture texture;

public:
    DrawerPlayer(player_t _player, SDL2pp::Renderer& renderer);

    void draw(SDL2pp::Renderer& renderer);

    void update_player(const player_t& update_player);  // quizas polimorfismo, asi el padre tiene 1
                                                        // type y los hijos lo usan como quieran
};

#endif  // DRAWER_PLAYER_H
