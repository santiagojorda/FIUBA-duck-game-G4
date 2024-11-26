#include "duck_state_jumping.h"

#include <iostream>

#include "../player.h"

#define JUMP_STEP 7

struct JumpingStateConfig {
    DuckStateType id = DuckStateType::JUMPING;
    std::string name = "Jumping";
};
JumpingStateConfig jumping_config;

DuckStateJumping::DuckStateJumping(const uint8_t& _player_id):
        DuckState(jumping_config.id, jumping_config.name,
                  duck_state_frames[jumping_config.id].max_frames, _player_id) {}

void DuckStateJumping::update_state(Positionable& positionable, GamePhysics& physics) {
    tick++;

    positionable.translate_y(-JUMP_STEP);
    if (tick == get_max_frames()) {
        positionable.fall(physics);
        // positionable.fall(physics); //decirle al physics que le haga fall
        return;
    }
    increment_frame();
}

DuckStateJumping::~DuckStateJumping() {}
