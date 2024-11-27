#include "event.h"

#include <iostream>

Event::Event(uint8_t& _player_id, const ActionEvent& _action_event)
    : player_id(_player_id),
    action_event(_action_event)
    {}


void Event::start(GameLogic& game_logic) {
    game_logic.handle_event(player_id, *this);
}

Event::~Event() {
    std::cout << "Se elimino action evento de player: " << (int)player_id << std::endl;
}