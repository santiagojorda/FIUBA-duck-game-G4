#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>

#include "../player/list_players.h"
#include "../player/player.h"

#include "game_physics.h"

class GameLogic {
private:
    ListPlayers& players;
    GamePhysics physics;
    Player& get_player(const uint8_t& player_id);

public:
    explicit GameLogic(ListPlayers& _players);
    void apply_gravity();
    void move_left_player(uint8_t player_id);
    void move_right_player(uint8_t player_id);
    void crouch_player(uint8_t player_id);
    void jump_player(uint8_t player_id);

    ~GameLogic();
};

#endif
