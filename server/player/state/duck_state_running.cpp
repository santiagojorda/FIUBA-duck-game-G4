#include "duck_state_running.h"

#include "../player.h"

#define RUN_STEP 10

struct RunningStateConfig {
    DuckStateType id = DuckStateType::IS_RUNNING; 
    std::string name = "Running";
};
RunningStateConfig running_config;

DuckStateRunning::DuckStateRunning(const uint8_t& _player_id, Direction& _direction): 
    DuckState(running_config.id, running_config.name, duck_state_frames[running_config.id].max_frames, _player_id),
    direction(_direction)
    {}

void DuckStateRunning::update(Player& player, GamePhysics& physics) {
    DuckState::update(player, physics);
}

void DuckStateRunning::execute(Player& player, GamePhysics& physics){
    (void)physics;
    player.translate_x(RUN_STEP);
}

DuckStateRunning::~DuckStateRunning() {}
