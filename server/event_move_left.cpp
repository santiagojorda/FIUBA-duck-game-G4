#include "event_move_left.h"

EventMoveLeft::EventMoveLeft() {}


void EventMoveLeft::transform_player(Player& player) {
    if (player.get_id() == this->id_player) {
        player.translate_x(-1);
    }
}


EventMoveLeft::~EventMoveLeft() {}
