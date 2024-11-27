#include "event_move_right.h"

EventMoveRight::EventMoveRight(uint8_t& _player_id) : EventPlayer(_player_id, ActionEvent::MOVE_RIGHT){}

void EventMoveRight::execute(Player& player, GameLogic& game_logic){
    player.run_right(game_logic.get_physics());
}; 
EventMoveRight::~EventMoveRight() {};