#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "../guns/list_guns.h"
#include "../guns/list_projectiles.h"
#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

struct GameState_t {
    // cppcheck-suppress unusedStructMember
    ListPlayers& players;
    Map& map;
    ListGuns& map_guns;
    ListProjectiles& map_projectiles;
};

#endif  // SERVER_GAME_STATE_H_
