#include "duck_state_dead.h"

struct DeadStateConfig {
    DuckStateType id = DuckStateType::IS_DEAD; 
    std::string name = "Dead"; 
};
DeadStateConfig dead_config;

DuckStateDead::DuckStateDead(Player& _player): DuckState(dead_config.id, dead_config.name, _player){}

void DuckStateDead::update(Player& player) {
    (void)player;
} 

DuckStateDead::~DuckStateDead() {}
