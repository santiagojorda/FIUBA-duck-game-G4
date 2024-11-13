#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>

#include "../../common/action_commands.h"
#include "../map/map.h"
#include "../player/list_players.h"
#include "../player/player.h"

#include "game_physics.h"

class GameLogic {
private:
    ListPlayers& players;
    Map& map;
    GamePhysics physics;
    Player& get_player(const uint8_t& player_id);
    void log_player_action(Player& player, const std::string& action);
    bool in_floor(const Player& player);

public:
    explicit GameLogic(ListPlayers& _players, Map& _map);
    void apply_gravity();
    void slove_collision();
    void handle_event(uint8_t player_id, ActionCommand event);

    ~GameLogic();
};

#endif
