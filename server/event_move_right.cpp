#include "event_move_right.h"

EventMoveRight::EventMoveRight() : EventPlayer() {}

void EventMoveRight::execute(GameLogic& game_logic) {
    game_logic.move_right_player(player_id);
}


EventMoveRight::~EventMoveRight() { EventPlayer::~EventPlayer();}
