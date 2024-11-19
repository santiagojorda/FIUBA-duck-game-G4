#include "duck_state_running.h"

#include "../player.h"

#define RUN_STEP 10

struct RunningStateConfig {
    DuckStateType id = DuckStateType::IS_RUNNING; 
    std::string name = "Running"; 
};
RunningStateConfig running_config;

DuckStateRunning::DuckStateRunning(Player& _player): DuckState(running_config.id, running_config.name, _player){}

void DuckStateRunning::update(Player& player) {
    DuckState::update(player);
    player.translate_x(RUN_STEP);
}

DuckStateRunning::~DuckStateRunning() {}
