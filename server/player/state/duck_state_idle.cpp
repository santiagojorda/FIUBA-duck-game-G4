#include "duck_state_idle.h"

struct IdleStateConfig {
    DuckStateType id = DuckStateType::IS_IDLE; 
    std::string name = "Idle"; 
};
IdleStateConfig idle_config;

DuckStateIdle::DuckStateIdle(Player& _player): DuckState(idle_config.id, idle_config.name, _player){}

void DuckStateIdle::update(Player& player) {
    (void)player;
} 
DuckStateIdle::~DuckStateIdle() {}
