#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>

#include "game_physics.h"
#include "../player/list_players.h"
#include "../player/player.h"
#include "../map/map.h"

class GameLogic {
private:
    ListPlayers& players;
    Map& map;
    GamePhysics physics;
    Player& get_player(const uint8_t& player_id);

public:
    explicit GameLogic(ListPlayers& _players, Map& _map);
    void apply_gravity();
    void move_left_player(uint8_t player_id);
    void move_right_player(uint8_t player_id);
    void crouch_player(uint8_t player_id);
    void jump_player(uint8_t player_id);

    ~GameLogic();
};

#endif
