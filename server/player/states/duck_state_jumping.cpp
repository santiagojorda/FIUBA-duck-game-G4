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

void DuckStateJumping::update(Player& player, GamePhysics& physics) {
    (void)physics;
    tick++;

    player.translate_y(-JUMP_STEP);
    if (tick == max_frames) {
        player.fall(physics);
        return;
    }
    frame++;
}

DuckStateJumping::~DuckStateJumping() {}
