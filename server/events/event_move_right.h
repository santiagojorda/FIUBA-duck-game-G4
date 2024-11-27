#ifndef EVENT_MOVE_RIGHT_H
#define EVENT_MOVE_RIGHT_H

#include "event.h"

class EventMoveRight: public Event {
public:
    explicit EventMoveRight(uint8_t& _player_id);

    virtual void execute(Player& player, GameLogic& game_logic) override; 
    ~EventMoveRight();
};

#endif
