#include "duck_state_dead.h"

struct DeadStateConfig {
    DuckStateType id = DuckStateType::IS_DEAD; 
    std::string name = "Dead"; 
};
DeadStateConfig dead_config;

DuckStateDead::DuckStateDead(): DuckState(dead_config.id, dead_config.name){}

void DuckStateDead::update(Player& player) {
    (void)player;
} 

DuckStateDead::~DuckStateDead() {}
