#include "duck_state_falling.h"

#include "../../attributes/positionable.h"

struct FallingStateConfig {
    DuckStateType id = DuckStateType::IS_FALLING; 
    std::string name = "Falling"; 
};
FallingStateConfig falling_config;

DuckStateFalling::DuckStateFalling(Player& _player, GamePhysics& _game_physics): 
    DuckState(falling_config.id, falling_config.name, _player),
    physics(_game_physics)
    {}
    
void DuckStateFalling::update(Player& player) {
    (void)player;
    physics.falling((Positionable&)(player), 1);
    // log_action("Fall");
} 
DuckStateFalling::~DuckStateFalling() {}
