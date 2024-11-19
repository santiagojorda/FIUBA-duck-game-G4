#include "duck_state_jumping.h"

struct JumpingStateConfig {
    DuckStateType id = DuckStateType::IS_JUMPING; 
    std::string name = "Jumping"; 
};
JumpingStateConfig jumping_config;

DuckStateJumping::DuckStateJumping(): DuckState(jumping_config.id, jumping_config.name){}

void DuckStateJumping::update(Player& player) {
    (void)player;
    
} 

DuckStateJumping::~DuckStateJumping() {}
