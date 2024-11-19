#include "duck_state_falling.h"

struct FallingStateConfig {
    DuckStateType id = DuckStateType::IS_FALLING; 
    std::string name = "Falling"; 
};
FallingStateConfig falling_config;

DuckStateFalling::DuckStateFalling(): DuckState(falling_config.id, falling_config.name){}
    
void DuckStateFalling::update(Player& player) {
    (void)player;

} 
DuckStateFalling::~DuckStateFalling() {}
