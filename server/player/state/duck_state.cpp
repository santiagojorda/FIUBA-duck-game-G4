
#include "duck_state.h"

#include <iostream>

#include "../player.h"

DuckState::DuckState(const DuckStateType& _state_id, const std::string& _state_name,
                     const uint8_t& _max_frames, const uint8_t& _player_id,
                     const Direction& _direction):
        state_id(_state_id),
        state_name(_state_name),
        max_frames(_max_frames),
        player_id(_player_id),
        direction(_direction) {
    init_state(_player_id);
}

DuckState::DuckState(const DuckStateType& _state_id, const std::string& _state_name,
                     const uint8_t& _max_frames, const uint8_t& _player_id):
        DuckState(_state_id, _state_name, _max_frames, _player_id, Direction::RIGHT) {}

void DuckState::init_state(const uint8_t& player_id) {
    std::cout << "State " << state_name << " of player " << (int)player_id << " is created "
              << std::endl;
    reset();
}

void DuckState::update(Player& player, GamePhysics& physics) {
    (void)physics;
    (void)player;
}
void DuckState::execute(Player& player, GamePhysics& physics) {
    (void)physics;
    (void)player;
}

void DuckState::reset() {
    tick = 0;
    frame = 0;
}

void DuckState::start() {
    std::cout << "Player " << (int)player_id << " is " << state_name << std::endl;

    reset();
}

void DuckState::finish() { reset(); }

void DuckState::set_direction(const Direction& _direction) { direction = _direction; }
Direction DuckState::get_direction() { return direction; }


DuckStateType DuckState::get_id() { return state_id; }
uint8_t DuckState::get_frame() { return frame; }
