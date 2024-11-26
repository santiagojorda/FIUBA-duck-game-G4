
#include "duck_state.h"

#include <iostream>


DuckState::DuckState(const DuckStateType& _state_id, const std::string& _state_name,
                     const uint8_t& _max_frames, const uint8_t& _player_id,
                     const Direction& _direction):
        State<DuckStateType>(_state_id, _state_name, _max_frames, _direction),
        player_id(_player_id)
        {
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

void DuckState::update_state(Positionable& positionable, GamePhysics& physics) {
    (void)physics;
    (void)positionable;
}
void DuckState::execute(Positionable& positionable, GamePhysics& physics) {
    (void)physics;
    (void)positionable;
}

void DuckState::reset() {
    State::reset();
    Updatable::reset();
}

void DuckState::start() {
    std::cout << "Player " << (int)player_id << " is " << state_name << std::endl;
    reset();
}

void DuckState::finish() { reset(); }


DuckState::~DuckState() {}
