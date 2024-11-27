#include "event_trigger.h"

EventTrigger::EventTrigger(uint8_t& _player_id) : Event(_player_id, ActionEvent::TRIGGER){}

void EventTrigger::execute(Player& player, GameLogic& game_logic){
    player.shoot(game_logic.get_projectiles(), ModeShoot::TRIGGER);
 }; 
EventTrigger::~EventTrigger() {};