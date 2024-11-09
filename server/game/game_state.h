#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "../player/list_players.h"
#include "../player/player.h"

struct GameState_t {
    // cppcheck-suppress unusedStructMember
    ListPlayers players;
};

#endif  // SERVER_GAME_STATE_H_
