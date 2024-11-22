#ifndef DUCK_STATE_FACTORY_h
#define DUCK_STATE_FACTORY_h

#include <cstdint>

#include "../../../common/state_duck.h"
#include "duck_state.h"
#include "duck_state_crouching.h"
#include "duck_state_dead.h"
#include "duck_state_falling.h"
#include "duck_state_idle.h"
#include "duck_state_jumping.h"
#include "duck_state_planning.h"
#include "duck_state_recoiling.h"
#include "duck_state_running.h"
#include "duck_state_slipping.h"

class DuckStateFactory{
private:
    // cppcheck-suppress unusedStructMember
    std::map<DuckStateType, DuckState*> states;

    // cppcheck-suppress unusedStructMember
    uint8_t player_id;

public:
    explicit DuckStateFactory(const uint8_t& _player_id): 
        player_id(_player_id) 
    {
        add(DuckStateType::RUNNING, new DuckStateRunning(_player_id));
        add(DuckStateType::JUMPING, new DuckStateJumping(_player_id));
        add(DuckStateType::FALLING, new DuckStateFalling(_player_id));
        add(DuckStateType::CROUCHING, new DuckStateCrouching(_player_id));
        add(DuckStateType::SLIPPING, new DuckStateSlipping(_player_id));
        add(DuckStateType::RECOILING, new DuckStateRecoiling(_player_id));
        add(DuckStateType::PLANNING, new DuckStatePlanning(_player_id));
        add(DuckStateType::DEAD, new DuckStateDead(_player_id));
        add(DuckStateType::IDLE, new DuckStateIdle(_player_id));
    }

    void add(const DuckStateType& state_id, DuckState* state){
        states[state_id] = state;
    }

    DuckState* get(const DuckStateType& state_id) {
        return states[state_id];
    }

    ~DuckStateFactory(){
        for (auto& state: states) {
            delete state.second;
        }
        states.clear();
    };
};

#endif  // EVENT_FACTORY_h
