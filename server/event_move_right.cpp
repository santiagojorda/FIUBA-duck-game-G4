#include "event_move_right.h"

EventMoveRight::EventMoveRight() {}

void EventMoveRight::transform_player(Player& player) {
    if (player.get_id() == this->id_player) {
        player.translate_x(1);
    }
}


EventMoveRight::~EventMoveRight() {}
