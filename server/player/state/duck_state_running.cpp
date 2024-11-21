#include "duck_state_running.h"

#include "../player.h"
#include <iostream>

#define RUN_STEP 3
#define TICKS_PER_FRAME 1

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
    (void)physics;
    std::cout << "steps updated    " << count_steps_updated << std::endl;
    std::cout << "steps to execute " << count_steps_to_execute << std::endl;
    if(count_steps_updated >= count_steps_to_execute){
        player.idle();
        return;
    }
    frame++;
    count_steps_updated++;
    move(player, direction);
    if(frame >= max_frames){
        reset();
    }
}

void DuckStateRunning::move(Player& player, Direction& direction){
    if (direction == Direction::RIGHT){
        player.translate_x(RUN_STEP);
    }
    else if(direction == Direction::LEFT){
        player.translate_x(-RUN_STEP);
    }
}

void DuckStateRunning::execute(Player& player, GamePhysics& physics){
    (void)physics;
    (void)player;

    count_steps_to_execute++;
}

DuckStateRunning::~DuckStateRunning() {}
