#include "duck_state_running.h"

#include <iostream>

#include "../player.h"

#define RUN_STEP 5
#define TICKS_PER_FRAME 1

struct RunningStateConfig {
    DuckStateType id = DuckStateType::RUNNING;
    std::string name = "Running";
};
RunningStateConfig running_config;

DuckStateRunning::DuckStateRunning(const uint8_t& _player_id):
        DuckState(running_config.id, running_config.name,
                  duck_state_frames[running_config.id].max_frames, _player_id) {}

void DuckStateRunning::update(Player& player, GamePhysics& physics) {
    (void)physics;
    (void)player;
    if (frame >= max_frames) {
        reset();
    }
}

void DuckStateRunning::move(Player& player, Direction& direction) {
    if (direction == Direction::RIGHT) {
        player.translate_x(RUN_STEP);
    } else if (direction == Direction::LEFT) {
        player.translate_x(-RUN_STEP);
    }
}

void DuckStateRunning::execute(Player& player, GamePhysics& physics) {
    DuckState::execute(player, physics);
    move(player, direction);
    frame++;
    count_steps_to_execute++;
}

DuckStateRunning::~DuckStateRunning() {}
