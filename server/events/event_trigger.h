#ifndef EVENT_TRIGGER_H
#define EVENT_TRIGGER_H

#include "event_player.h"

class EventTrigger: public EventPlayer {
public:
    explicit EventTrigger(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::TRIGGER){}

    ~EventTrigger() {};
};


#endif
