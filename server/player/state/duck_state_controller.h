#ifndef DUCK_STATE_CONTROLLER_H
#define DUCK_STATE_CONTROLLER_H

#include <cstdint>
#include <string>
#include "../../../common/state_duck.h"
#include "../../../common/direction.h"
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

class Duck;
class GamePhysics;

class DuckStateController {
private:
    DuckState* current_state;

    void set_state(DuckState* new_state){
        if(new_state){
            delete current_state;
            current_state = new_state;
        }
    }

public:
    DuckStateController() {
        DuckState* initial_state = new DuckStateIdle();
        current_state = initial_state;
    }

    void update(Player& player){
        if(current_state){
            current_state->update(player);
        }
    };

    void run_right(){
        set_state(new DuckStateRunning());
    }
    void run_left(){
        set_state(new DuckStateRunning());
    }
    void run(Direction& direction){
        (void)direction;
        set_state(new DuckStateRunning());
    } 
    void jump(){
        set_state(new DuckStateJumping());
    }
    void fall(GamePhysics& physics){
        (void)physics;
        set_state(new DuckStateFalling());
    }
    void crouch(){
        set_state(new DuckStateCrouching());
    }
    void slip(){
        set_state(new DuckStateSlipping());
    }
    void recoil(){
        set_state(new DuckStateRecoiling());
    }
    void plane(){
        set_state(new DuckStatePlanning());
    }
    void die(){
        set_state(new DuckStateDead());
    }
    void idle(){
        set_state(new DuckStateIdle());
    }

    bool is_jumping() { 
        if(current_state){
            return current_state->get_id() == DuckStateType::IS_JUMPING;
        }
        return false;
    }
    bool is_dead() { 
        if(current_state){
            return current_state->get_id() == DuckStateType::IS_DEAD;
        }
        return false;
    }


    DuckStateType get_state() { return current_state->get_id();};
    uint8_t get_frame() { return current_state->get_frame(); };

    ~DuckStateController() {
        delete current_state;
    }
};

#endif