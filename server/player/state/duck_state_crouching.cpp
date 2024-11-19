#include "duck_state_crouching.h"

struct CrouchingStateConfig {
    DuckStateType id = DuckStateType::IS_CROUCHING; 
    std::string name = "Crouching"; 
};
CrouchingStateConfig crouching_config;

DuckStateCrouching::DuckStateCrouching(Player& _player): DuckState(crouching_config.id, crouching_config.name, _player){}

void DuckStateCrouching::update(Player& player) {
    (void)player;
};

DuckStateCrouching::~DuckStateCrouching() {}
