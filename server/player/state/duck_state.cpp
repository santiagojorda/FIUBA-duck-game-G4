
#include "duck_state.h"
#include "../player.h"
#include <iostream>

DuckState::DuckState(const DuckStateType& _state_id, const std::string& _state_name, const uint8_t& _max_frame, const uint8_t& _player_id) :
    state_id(_state_id),
    state_name(_state_name),
    max_frame(_max_frame),
    player_id(_player_id)
    {
        std::cout << "Player " << (int)player_id << " is " << state_name << std::endl;
        reset();
    }

void DuckState::update(Player& player, GamePhysics& physics){
    (void)physics;
    (void)player;
    tick++;
}
void DuckState::execute(Player& player, GamePhysics& physics){
    (void)physics;
    (void)player;
}
void DuckState::reset() {
    tick = 0;
    frame = 0;
}

DuckStateType DuckState::get_id() { return state_id; }
uint8_t DuckState::get_frame() { return frame; }
