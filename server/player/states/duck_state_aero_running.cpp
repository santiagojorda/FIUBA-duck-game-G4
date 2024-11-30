#include "duck_state_aero_running.h"

#include <iostream>
struct RunningStateConfig {
    DuckStateType id = DuckStateType::AERO_RUNNING;
    std::string name = "Aero Running";
};
RunningStateConfig aero_running_config;

DuckStateAeroRunning::DuckStateAeroRunning(const uint8_t& _player_id):
        DuckState(aero_running_config.id, aero_running_config.name,
                  duck_state_frames[aero_running_config.id].max_frames, _player_id) {}

void DuckStateAeroRunning::move(Positionable& positionable) {
    if (is_right()) {
        positionable.translate_x(RUN_STEP);
    } else if (is_left()) {
        positionable.translate_x(-RUN_STEP);
    }
}

void DuckStateAeroRunning::execute(Positionable& positionable, GameLogic& game_logic) {
    DuckState::execute(positionable, game_logic);
    move(positionable);
    increment_frame();
}

DuckStateAeroRunning::~DuckStateAeroRunning() {}
