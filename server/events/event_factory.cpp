#include "event_factory.h"

#include "event_crouch.h"
#include "event_jump.h"
#include "event_move_left.h"
#include "event_move_right.h"
#include "event_shoot.h"
#include "event_idle.h"


EventFactory::EventFactory(uint8_t& _player_id): player_id(_player_id) {

    this->map_event[MOVE_LEFT] = new EventMoveLeft(player_id);
    this->map_event[MOVE_RIGHT] = new EventMoveRight(player_id);
    this->map_event[JUMP] = new EventJump(player_id);
    this->map_event[CROUCH] = new EventCrouch(player_id);
    this->map_event[SHOOT] = new EventShoot(player_id);
     this->map_event[IDLE] = new EventIdle(player_id);
    // this->map_event[CROUCH] = ;
    // this->map_event[MOVE_LEFT] = ;
}

EventFactory::EventFactory(const EventFactory& _other): EventFactory(_other.player_id) {}

EventPlayer* EventFactory::get_event(uint8_t _event_id) { return this->map_event[_event_id]; }

EventFactory::~EventFactory() {
    for (auto tupla: this->map_event) {
        delete tupla.second;
    }
}