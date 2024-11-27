#include "event_player.h"

#include <iostream>

EventPlayer::EventPlayer(uint8_t& _player_id, const ActionEvent& _action_event)
    : player_id(_player_id),
    action_event(_action_event)
    {}


void EventPlayer::start(GameLogic& game_logic) {
    game_logic.handle_event(player_id, *this);
}

EventPlayer::~EventPlayer() {
    std::cout << "Se elimino action evento de player: " << (int)player_id << std::endl;
}