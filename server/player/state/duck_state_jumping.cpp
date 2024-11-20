#include "duck_state_jumping.h"
#include "../player.h"

struct JumpingStateConfig {
    DuckStateType id = DuckStateType::IS_JUMPING; 
    std::string name = "Jumping"; 
};
JumpingStateConfig jumping_config;

DuckStateJumping::DuckStateJumping(const uint8_t& _player_id): 
    DuckState(jumping_config.id, jumping_config.name, duck_state_frames[jumping_config.id].max_frames, _player_id)
    {}

void DuckStateJumping::update(Player& player, GamePhysics& physics) {
    (void)physics;

    player.translate_y(-10);

    if(tick == 6){
        player.fall(physics);
        return;
    }

    if (tick == 2 || tick == 4){
        frame++;
    }


} 

DuckStateJumping::~DuckStateJumping() {}
