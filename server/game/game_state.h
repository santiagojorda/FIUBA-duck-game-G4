#ifndef SERVER_GAME_STATE_H_
#define SERVER_GAME_STATE_H_

#include <list>

#include "list_items_map.h"
#include "../weapons/list_projectiles.h"
#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

struct ItemsMap_t{
    uint8_t texture_id;
    Coordinate coordinate;
    // uint8_t frame;
};

struct Projectiles_t{
    uint8_t texture_id;
    Coordinate coordinate;
};

struct GameState_t {
    // cppcheck-suppress unusedStructMember
    ListPlayers& players;
    Map& map;
    std::list<ItemsMap_t> map_items;
    std::list<Projectiles_t> map_projectiles;
};


#endif  // SERVER_GAME_STATE_H_
