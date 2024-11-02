#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>

#include "list_players.h"
#include "player.h"

class GameLogic {
private:
    ListPlayers& players;
    void get_player(Player& player, uint8_t player_id);

public:
    explicit GameLogic(ListPlayers& _players);
    void move_left_player(uint8_t player_id);
    void move_right_player(uint8_t player_id);
    void crouch_player(uint8_t player_id);
    void jump_player(uint8_t player_id);

    Player& get_player(const uint8_t& player_id);
    ~GameLogic();
};

#endif
