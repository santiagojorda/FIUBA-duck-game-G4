#include "duck_state_controller.h"

#include "../player.h"

DuckStateController::DuckStateController(const uint8_t& _player_id){
    DuckState* initial_state = new DuckStateIdle(_player_id);
    current_state = initial_state;
    direction = Direction::RIGHT;
}

void DuckStateController::set_state(DuckState* new_state){
    if(new_state){
        delete current_state;
        current_state = new_state;
    }
}
void DuckStateController::update(Player& player, GamePhysics& physics){
    if(current_state){
        current_state->update(player, physics);
    }
};

void DuckStateController::run_right(Player& player, GamePhysics& physics){
    direction = Direction::RIGHT;
    set_state(new DuckStateRunning(player.get_id(), direction));
    current_state->execute(player, physics);
}
void DuckStateController::run_left(Player& player, GamePhysics& physics){
    direction = Direction::LEFT;
    set_state(new DuckStateRunning(player.get_id(), direction));
    current_state->execute(player, physics);
}
void DuckStateController::jump(Player& player, GamePhysics& physics){
    if(!is_jumping()){
        set_state(new DuckStateJumping(player.get_id()));
        current_state->execute(player, physics);
    }
}
void DuckStateController::fall(Player& player, GamePhysics& physics){ 
    set_state(new DuckStateFalling(player.get_id())); 
    current_state->execute(player, physics);
}
void DuckStateController::crouch(Player& player, GamePhysics& physics){ 
    set_state(new DuckStateCrouching(player.get_id())); 
    current_state->execute(player, physics);
}
void DuckStateController::slip(Player& player, GamePhysics& physics){ 
    set_state(new DuckStateSlipping(player.get_id())); 
    current_state->execute(player, physics);
}
void DuckStateController::recoil(Player& player, GamePhysics& physics){ 
    set_state(new DuckStateRecoiling(player.get_id())); 
    current_state->execute(player, physics);
}
void DuckStateController::plane(Player& player, GamePhysics& physics){ 
    set_state(new DuckStatePlanning(player.get_id())); 
    current_state->execute(player, physics);
}
void DuckStateController::die(Player& player){ set_state(new DuckStateDead(player.get_id())); }
void DuckStateController::idle(Player& player){ set_state(new DuckStateIdle(player.get_id())); }

bool DuckStateController::is_in_state(DuckStateType state) {
    return current_state && current_state->get_id() == state;
}

bool DuckStateController::is_jumping() { return is_in_state(DuckStateType::IS_JUMPING);}
bool DuckStateController::is_dead() { return is_in_state(DuckStateType::IS_DEAD);}
bool DuckStateController::is_running() { return is_in_state(DuckStateType::IS_RUNNING);}

DuckStateType DuckStateController::get_state() { return current_state->get_id();};
uint8_t DuckStateController::get_frame() { return current_state->get_frame(); };

DuckStateController::~DuckStateController() {
    delete current_state;
}
