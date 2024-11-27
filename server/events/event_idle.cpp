#include "event_idle.h"


EventIdle::EventIdle(uint8_t& _player_id): EventPlayer(_player_id) {}

void EventIdle::execute(GameLogic& game_logic) {
    game_logic.handle_event(player_id, ActionEvent::IDLE);
}

EventIdle::~EventIdle() {}
