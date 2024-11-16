#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>

#include "../../common/action_commands.h"
#include "../guns/list_guns.h"
#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

#include "game_physics.h"

class GameLogic {
private:
    ListPlayers& players;
    Map& map;
    ListGuns& guns;
    GamePhysics physics;
    Player& get_player(const uint8_t& player_id);
    void log_player_action(Player& player, const std::string& action);
    void update_player_gravity(Player& player);
    void update_player_equip_collision(Player& player);

    bool is_player_floor_collision(Player& player);

public:
    explicit GameLogic(ListPlayers& _players, Map& _map, ListGuns& _guns);
    void handle_event(uint8_t player_id, ActionCommand event);
    void update_players();
    ~GameLogic();
};

#endif
