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

void DuckStateRunning::update_state(Positionable& positionable, GamePhysics& physics) {
    (void)physics;
    (void)positionable;
    if (frame_handler.has_reached_max_frames()) {
        reset();
    }
}

void DuckStateRunning::move(Positionable& positionable) {
    if (direction_handler.is_right()) {
        positionable.translate_x(RUN_STEP);
    } else if (direction_handler.is_left()) {
        positionable.translate_x(-RUN_STEP);
    }
}

void DuckStateRunning::execute(Positionable& positionable, GamePhysics& physics) {
    DuckState::execute(positionable, physics);
    move(positionable);
    frame_handler.increment_frame();
}

DuckStateRunning::~DuckStateRunning() {}
