#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

struct GameState_t {
    // cppcheck-suppress unusedStructMember
    ListPlayers& players;
    ListProjectiles& projectiles;
    Map& map;
};

#endif  // SERVER_GAME_STATE_H_
