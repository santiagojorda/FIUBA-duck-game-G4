#include "event_jump.h"

EventJump::EventJump(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::JUMP){}

void EventJump::execute(Player& player, GameLogic& game_logic){
    player.jump(game_logic.get_physics());
}; 
EventJump::~EventJump() {};