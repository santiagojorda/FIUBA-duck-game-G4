#include "event_move_left.h"

EventMoveLeft::EventMoveLeft(uint8_t& _player_id) : EventPlayer(_player_id) {}

void EventMoveLeft::execute(GameLogic& game_logic) {
    game_logic.move_left_player(player_id);
}

EventMoveLeft::~EventMoveLeft() {EventPlayer::~EventPlayer();}