#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>
#include "player.h"

class GameLogic {
private:
    std::list<Player>& players;
    void get_player(Player& player, uint8_t player_id);

public:
    GameLogic(std::list<Player>& _players);
    void move_left_player(uint8_t player_id);
    void move_right_player(uint8_t player_id);

    Player get_player(uint8_t player_id);
    ~GameLogic();
};

#endif
