#include "event_jump.h"

EventJump::EventJump(uint8_t& _player_id): EventPlayer(_player_id) {}

void EventJump::execute(GameLogic& game_logic) {
    game_logic.handle_event(player_id, ActionCommand::JUMP);
}

EventJump::~EventJump() { EventPlayer::~EventPlayer(); }
