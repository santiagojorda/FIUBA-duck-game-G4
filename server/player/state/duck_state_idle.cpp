#include "duck_state_idle.h"

struct IdleStateConfig {
    DuckStateType id = DuckStateType::IS_IDLE; 
    std::string name = "Idle"; 
};
IdleStateConfig idle_config;

DuckStateIdle::DuckStateIdle(): DuckState(idle_config.id, idle_config.name){}

void DuckStateIdle::update(Player& player) {
    (void)player;
} 
DuckStateIdle::~DuckStateIdle() {}
