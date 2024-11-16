#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"
#include "../guns/list_guns.h"
#include "../guns/list_projectiles.h"

struct GameState_t {
    // cppcheck-suppress unusedStructMember
    ListPlayers& players;
    ListProjectiles& projectiles;
    Map& map;
    ListGuns& map_guns;
};

#endif  // SERVER_GAME_STATE_H_
