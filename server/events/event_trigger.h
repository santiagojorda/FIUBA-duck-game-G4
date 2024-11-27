#ifndef EVENT_TRIGGER_H
#define EVENT_TRIGGER_H

#include "event_player.h"

class EventTrigger: public EventPlayer {
public:
    explicit EventTrigger(uint8_t& _player_id);

    virtual void execute(Player& player, GameLogic& game_logic) override; 
    ~EventTrigger();
};


#endif
