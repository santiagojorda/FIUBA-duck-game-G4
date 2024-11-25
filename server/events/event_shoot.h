#ifndef EVENT_SHOOT_H
#define EVENT_SHOOT_H

#include "event_player.h"

class EventShoot: public EventPlayer {
public:
    explicit EventShoot(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::SHOOT){}

    ~EventShoot() {};
};


#endif  // EVENT_SHOOT_H
