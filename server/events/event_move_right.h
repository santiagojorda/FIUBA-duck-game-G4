#ifndef EVENT_MOVE_RIGHT_H
#define EVENT_MOVE_RIGHT_H

#include "event_player.h"

class EventMoveRight: public EventPlayer {
public:
    explicit EventMoveRight(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::MOVE_RIGHT){}

    ~EventMoveRight() {};
};


#endif  // EVENT_MOVE_RIGHT_H
