#include "event_move_right.h"

EventMoveRight::EventMoveRight(uint8_t& _player_id): EventPlayer(_player_id) {}

void EventMoveRight::execute(GameLogic& game_logic) {
    game_logic.handle_event(player_id, ActionCommand::MOVE_RIGHT);
}

EventMoveRight::~EventMoveRight() { EventPlayer::~EventPlayer(); }
