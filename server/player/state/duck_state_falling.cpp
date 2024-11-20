#include "duck_state_falling.h"

#include "../../attributes/positionable.h"
#include "../player.h"

struct FallingStateConfig {
    DuckStateType id = DuckStateType::IS_FALLING; 
    std::string name = "Falling"; 
};
FallingStateConfig falling_config;

DuckStateFalling::DuckStateFalling(const uint8_t& _player_id): 
    DuckState(falling_config.id, falling_config.name, duck_state_frames[falling_config.id].max_frames, _player_id)
    {}
    
void DuckStateFalling::update(Player& player, GamePhysics& physics) {
    player.translate_y(1);
    (void)physics;
}
DuckStateFalling::~DuckStateFalling() {}
