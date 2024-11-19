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
    DuckStateController(Player& player) {
        DuckState* initial_state = new DuckStateIdle(player);
        current_state = initial_state;
    }

    void update(Player& player){
        if(current_state){
            current_state->update(player);
        }
    };

    void run_right(Player& player){
        set_state(new DuckStateRunning(player));
    }
    void run_left(Player& player){
        set_state(new DuckStateRunning(player));
    }
    void run(Player& player, Direction& direction){
        (void)direction;
        set_state(new DuckStateRunning(player));
    } 
    void jump(Player& player){
        set_state(new DuckStateJumping(player));
    }
    void fall(Player& player, GamePhysics physics){
        (void)physics;
        set_state(new DuckStateFalling(player, physics));
    }
    void crouch(Player& player){
        set_state(new DuckStateCrouching(player));
    }
    void slip(Player& player){
        set_state(new DuckStateSlipping(player));
    }
    void recoil(Player& player){
        set_state(new DuckStateRecoiling(player));
    }
    void plane(Player& player){
        set_state(new DuckStatePlanning(player));
    }
    void die(Player& player){
        set_state(new DuckStateDead(player));
    }
    void idle(Player& player){
        set_state(new DuckStateIdle(player));
    }

    bool is_in_state(DuckStateType state) {
        return current_state && current_state->get_id() == state;
    }

    bool is_jumping() { return is_in_state(DuckStateType::IS_JUMPING);}
    bool is_dead() { return is_in_state(DuckStateType::IS_DEAD);}
    bool is_running() { return is_in_state(DuckStateType::IS_RUNNING);}

    DuckStateType get_state() { return current_state->get_id();};
    uint8_t get_frame() { return current_state->get_frame(); };

    ~DuckStateController() {
        delete current_state;
    }
};

#endif