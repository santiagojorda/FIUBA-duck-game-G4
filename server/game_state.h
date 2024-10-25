#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <vector>

#include "player.h"

struct GameState_t {
    uint8_t N_players;
    std::vector<Player> players;
};

#endif  // SERVER_GAME_STATE_H_
