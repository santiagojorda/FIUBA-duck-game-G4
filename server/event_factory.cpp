#include "event_factory.h"

#include "event_move_left.h"
#include "event_move_right.h"


EventFactory::EventFactory() {
    this->map_event[MOVE_LEFT] = new EventMoveLeft;
    this->map_event[MOVE_RIGHT] = new EventMoveRight;
    // this->map_event[JUMP] = ;
    // this->map_event[CROUCH] = ;
    // this->map_event[MOVE_LEFT] = ;
}

Event* EventFactory::get_event(uint8_t id_event, uint8_t id_player) {
    std::cout << id_player << std::endl; // para que no tire warning
    this->map_event[id_event]->set_id(id_event);
    return this->map_event[id_event];
}


EventFactory::~EventFactory() {
    for (auto tupla: this->map_event) {
        delete tupla.second;
    }
}