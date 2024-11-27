#ifndef EVENT_MOVE_LEFT_H
#define EVENT_MOVE_LEFT_H

#include "event_player.h"

class EventMoveLeft: public EventPlayer {
public:
    explicit EventMoveLeft(uint8_t& _player_id);

    virtual void execute(Player& player, GameLogic& game_logic) override; 
    ~EventMoveLeft();
};

#endif
