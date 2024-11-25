#ifndef EVENT_MOVE_LEFT_H
#define EVENT_MOVE_LEFT_H

#include "event_player.h"

class EventMoveLeft: public EventPlayer {
public:
    explicit EventMoveLeft(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::MOVE_LEFT){}

    ~EventMoveLeft() {};
};

#endif
