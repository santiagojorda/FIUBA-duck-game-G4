#ifndef EVENT_MOVE_RIGHT_H
#define EVENT_MOVE_RIGHT_H

#include "event_player.h"

class EventMoveRight: public EventPlayer {
public:
    explicit EventMoveRight(uint8_t& _player_id);

    virtual void execute(Player& player, GameLogic& game_logic) override; 
    ~EventMoveRight();
};

#endif
