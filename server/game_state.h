#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "list_players.h"
#include "player.h"

struct GameState_t {
    // cppcheck-suppress unusedStructMember
    uint8_t N_players;

    // cppcheck-suppress unusedStructMember
    ListPlayers players;
};

#endif  // SERVER_GAME_STATE_H_
