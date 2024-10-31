#include "event_player.h"

EventPlayer::EventPlayer() {}


void EventPlayer::set_id(const uint8_t& id_player) {
    this->id_player = id_player;
}

const uint8_t& EventPlayer::get_id() const {  // get_id en lugar de set_id
    return id_player;
}

EventPlayer::~EventPlayer() {}
