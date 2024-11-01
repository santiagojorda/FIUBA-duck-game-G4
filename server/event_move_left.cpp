#include "event_move_left.h"

EventMoveLeft::EventMoveLeft() : EventPlayer() {}

void EventMoveLeft::execute(GameLogic& game_logic) {
    game_logic.move_left_player(player_id);
}


EventMoveLeft::~EventMoveLeft() {EventPlayer::~EventPlayer();}
