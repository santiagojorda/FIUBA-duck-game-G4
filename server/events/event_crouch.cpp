#include "event_crouch.h"

EventCrouch::EventCrouch(uint8_t& _player_id) : Event(_player_id, ActionEvent::CROUCH){}

void EventCrouch::execute(Player& player, GameLogic& game_logic){
    player.crouch(game_logic.get_physics());
}; 
EventCrouch::~EventCrouch() {};