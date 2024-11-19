#include "duck_state_running.h"

struct RunningStateConfig {
    DuckStateType id = DuckStateType::IS_RUNNING; 
    std::string name = "Running"; 
};
RunningStateConfig running_config;

DuckStateRunning::DuckStateRunning(): DuckState(running_config.id, running_config.name){}

void DuckStateRunning::update(Player& player) {
    (void)player;
    
}

DuckStateRunning::~DuckStateRunning() {}
