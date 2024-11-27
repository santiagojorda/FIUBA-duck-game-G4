#include "event_idle.h"

EventIdle::EventIdle(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::IDLE){}

void EventIdle::execute(Player& player, GameLogic& game_logic) {
    (void)game_logic;
    player.idle();
} 
EventIdle::~EventIdle() {};