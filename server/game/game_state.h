#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "list_items_map.h"
#include "game_statistics.h"
#include "../weapons/list_projectiles.h"
#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

enum GameMoment  { DISPLAY_INFO, IN_GAME, FINISHED };

struct GameState_t {
    GameMoment moment;
    ListPlayers& players;
    Map& map;
    ListItemsMap& map_items;
    ListProjectiles map_projectiles;
    game_statistics_t statistics;
};


#endif  // SERVER_GAME_STATE_H_
