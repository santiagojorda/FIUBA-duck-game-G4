#include "event_player.h"

#include <iostream>

EventPlayer::EventPlayer(uint8_t& _player_id, const ActionEvent& _action_event)
    : player_id(_player_id),
    action_event(_action_event)
    {}


void EventPlayer::execute(GameLogic& game_logic) {
    game_logic.handle_event(player_id, action_event);
}

EventPlayer::~EventPlayer() {
    std::cout << "Se elimino action eventn de " << (int)player_id << std::endl;
}