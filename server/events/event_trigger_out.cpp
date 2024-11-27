#include "event_trigger_out.h"

EventTriggerOut::EventTriggerOut(uint8_t& _player_id) : Event(_player_id, ActionEvent::TRIGGER_OUT){}

void EventTriggerOut::execute(Player& player, GameLogic& game_logic){
    player.shoot(game_logic.get_projectiles(), ModeShoot::TRIGGER_OUT);
 }; 
EventTriggerOut::~EventTriggerOut() {};