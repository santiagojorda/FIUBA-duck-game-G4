#include "event_move_right.h"

EventMoveRight::EventMoveRight(uint8_t& _player_id): EventPlayer(_player_id) {}

void EventMoveRight::execute(GameLogic& game_logic) { game_logic.move_right_player(player_id); }

EventMoveRight::~EventMoveRight() { EventPlayer::~EventPlayer(); }
