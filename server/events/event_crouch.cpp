#include "event_crouch.h"

EventCrouch::EventCrouch(uint8_t& _player_id): EventPlayer(_player_id) {}

void EventCrouch::execute(GameLogic& game_logic) { game_logic.handle_event(player_id, ActionCommand::CROUCH); }

EventCrouch::~EventCrouch() { EventPlayer::~EventPlayer(); }
