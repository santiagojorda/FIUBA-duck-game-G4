#ifndef EVENT_JUMP_H
#define EVENT_JUMP_H

#include "event_player.h"

class EventJump: public EventPlayer {
public:
    explicit EventJump(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::JUMP){}

    ~EventJump() {};
};

#endif 
