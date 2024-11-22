#include "event_player.h"

#include <iostream>

EventPlayer::EventPlayer(uint8_t& _player_id): player_id(_player_id) {}

EventPlayer::~EventPlayer() {
    std::cout << "se elimino evento" << std::endl;
}