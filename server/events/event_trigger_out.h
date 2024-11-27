#ifndef EVENT_TRIGGER_OUT_H
#define EVENT_TRIGGER_OUT_H

#include "event_player.h"

class EventTriggerOut: public EventPlayer {
public:
    explicit EventTriggerOut(uint8_t& _player_id);

    virtual void execute(Player& player, GameLogic& game_logic) override; 
    ~EventTriggerOut();
};


#endif  // EVENT_SHOOT_H
