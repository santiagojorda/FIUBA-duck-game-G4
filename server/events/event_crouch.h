#ifndef EVENT_CROUCH_H
#define EVENT_CROUCH_H

#include "event_player.h"

class EventCrouch: public EventPlayer {
public:
    explicit EventCrouch(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::CROUCH){}

    ~EventCrouch() {};
};

#endif 