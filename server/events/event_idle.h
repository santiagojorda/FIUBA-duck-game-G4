#ifndef EVENT_IDLE_H
#define EVENT_IDLE_H

#include "event_player.h"

class EventIdle: public EventPlayer {
public:
    explicit EventIdle(uint8_t& _player_id);

    virtual void execute(Player& player, GameLogic& game_logic) override; 
    ~EventIdle();
};

#endif  