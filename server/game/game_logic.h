#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>
#include <memory>

#include "../../common/action_events.h"
#include "list_items_map.h"
#include "../weapons/list_projectiles.h"
#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

#include "../attributes/equippable.h"
class Event;
#include "game_physics.h"

class GameLogic {
private:
    ListPlayers& players;
    Map& map;
    ListItemsMap& items;
    ListProjectiles& projectiles;
    GamePhysics physics;
    void update_player_equip_collision(Player& player);
    void update_players();
    void update_projectiles();

public:
    explicit GameLogic(ListPlayers& _players, Map& _map, ListItemsMap& _items,
                       ListProjectiles& _projectiles);
    void handle_event(Event& event);
    void update();
    ListProjectiles& get_projectiles();
    GamePhysics& get_physics();
    Player& get_player(const uint8_t& player_id);
    void handle_drop(std::shared_ptr<Equippable> item);
    ~GameLogic();
};

#endif
