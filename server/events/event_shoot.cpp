#include "event_shoot.h"


EventShoot::EventShoot(uint8_t& _player_id): EventPlayer(_player_id) {}

void EventShoot::execute(GameLogic& game_logic) {
    game_logic.handle_event(player_id, ActionCommand::SHOOT);
}

EventShoot::~EventShoot() { EventPlayer::~EventPlayer(); }
