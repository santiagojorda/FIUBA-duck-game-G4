#include "duck_state_running.h"

#include <iostream>

#define RUN_STEP 5
#define TICKS_PER_FRAME 1

struct RunningStateConfig {
    DuckStateType id = DuckStateType::RUNNING;
    std::string name = "Running";
};
RunningStateConfig running_config;

DuckStateRunning::DuckStateRunning(uint8_t _player_id):
        DuckState(running_config.id, running_config.name,
                  duck_state_frames[running_config.id].max_frames, _player_id) {}

void DuckStateRunning::update_state(Positionable& positionable, GameLogic& game_logic) {
    (void)game_logic;
    (void)positionable;
    if (has_reached_max_frames()) {
        reset();
    }
}

void DuckStateRunning::move(Positionable& positionable) {
    if (is_right()) {
        positionable.translate_x(RUN_STEP);
    } else if (is_left()) {
        positionable.translate_x(-RUN_STEP);
    }
}

void DuckStateRunning::execute(Positionable& positionable, GameLogic& game_logic) {
    DuckState::execute(positionable, game_logic);
    move(positionable);
    increment_frame();
}

DuckStateRunning::~DuckStateRunning() {}
