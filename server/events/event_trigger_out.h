#ifndef EVENT_TRIGGER_OUT_H
#define EVENT_TRIGGER_OUT_H

#include "event_player.h"

class EventTriggerOut: public EventPlayer {
public:
    explicit EventTriggerOut(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::TRIGGER_OUT){}

    ~EventTriggerOut() {};
};


#endif  // EVENT_SHOOT_H
