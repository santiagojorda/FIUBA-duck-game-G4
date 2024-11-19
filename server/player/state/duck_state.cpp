
#include "duck_state.h"
#include "../player.h"
#include <iostream>

DuckState::DuckState(const DuckStateType& _state_id, const std::string& _state_name, const Player& _player):
    state_id(_state_id),
    state_name(_state_name),
    player_id(_player.get_id())
    {
        std::cout << (int)player_id << " is " << state_name << std::endl;
        reset();
    }

void DuckState::update(Player& player){
    (void)player;
    tick++;
    frame++;
}
void DuckState::reset() {
    tick = 0;
    frame = 0;
}

DuckStateType DuckState::get_id() { return state_id; }
uint8_t DuckState::get_frame() { return frame; }
