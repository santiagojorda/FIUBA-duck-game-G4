#include "duck_state_controller.h"

#include <iostream>

#include "player.h"

DuckStateController::DuckStateController(const uint8_t& _player_id)
        : StateController(std::make_shared<DuckStateFactory>(_player_id))
        {
            set_state(DuckStateType::IDLE);
            direction = current_state->get_direction();
        }

void DuckStateController::set_direction(const Direction& new_direction) {
    if (new_direction != current_state->get_direction()) {
        direction = new_direction;
        current_state->set_direction(direction);
    }
}

void DuckStateController::set_alive_state(const DuckStateType new_state_type){
    if(is_alive()){
        set_state(new_state_type);
    }
}

void DuckStateController::execute(Player& player, GameLogic& game_logic) {
    current_state->execute(player, game_logic);
}

void DuckStateController::run(Direction direction, Player& player, GameLogic& game_logic) {
    if(is_alive()){

        if (!is_running()) {
            set_alive_state(DuckStateType::RUNNING);
        }
        if (current_state->get_direction() != direction) {
            set_direction(direction);
        }
        execute(player, game_logic);

    }
}

void DuckStateController::run_right(Player& player, GameLogic& game_logic) {
    run(Direction::RIGHT, player, game_logic);
}
void DuckStateController::run_left(Player& player, GameLogic& game_logic) {
    run(Direction::LEFT, player, game_logic);
}

void DuckStateController::jump(Player& player, GameLogic& game_logic) {
    (void)player;
    (void)game_logic;
    if(!is_jumping() && !is_falling()){
        set_alive_state(DuckStateType::JUMPING);
    }
}
void DuckStateController::fall(Player& player, GameLogic& game_logic) {
    (void)player;
    (void)game_logic;
    // if(!player.){
    set_alive_state(DuckStateType::FALLING);
    // }
}
void DuckStateController::crouch(Player& player, GameLogic& game_logic) {
    (void)player;
    (void)game_logic;
    // if(player.is_touching_floor()){
    set_alive_state(DuckStateType::CROUCHING);
    // }
}
void DuckStateController::slip(Player& player, GameLogic& game_logic) {
    (void)player;
    (void)game_logic;
    // if(player.is_touching_floor()){
    set_alive_state(DuckStateType::SLIPPING);
    // }
}
void DuckStateController::recoil(Player& player, GameLogic& game_logic) {
    (void)player;
    (void)game_logic;
    set_alive_state(DuckStateType::RECOILING);
}
void DuckStateController::plane(Player& player, GameLogic& game_logic) {
    if(is_alive()){
        set_state(DuckStateType::PLANNING);
        execute(player, game_logic);
    }
}
void DuckStateController::die(Player& player) {
    (void)player;
    if (!is_dead()) {
        set_alive_state(DuckStateType::DEAD);
    }
}
void DuckStateController::idle(Player& player) {
    (void)player;
    // if (player.is_touching_floor()) {
    set_alive_state(DuckStateType::IDLE);
    // }
}
bool DuckStateController::is_jumping() { return is_in_state(DuckStateType::JUMPING); }
bool DuckStateController::is_running() { return is_in_state(DuckStateType::RUNNING); }
bool DuckStateController::is_falling() { return is_in_state(DuckStateType::FALLING); }
bool DuckStateController::is_dead() { return is_in_state(DuckStateType::DEAD); }
bool DuckStateController::is_idle() { return is_in_state(DuckStateType::IDLE); }
bool DuckStateController::is_alive() { return !is_in_state(DuckStateType::DEAD); }

DuckStateType DuckStateController::get_state() { return current_state->get_id(); };
uint8_t DuckStateController::get_frame() { return current_state->get_frame(); };
Direction DuckStateController::get_direction() { return direction; }
DuckStateController::~DuckStateController() {}
