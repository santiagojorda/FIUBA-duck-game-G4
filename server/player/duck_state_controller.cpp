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

void DuckStateController::execute(Player& player, GamePhysics& physics) {
    current_state->execute(player, physics);
}

void DuckStateController::run(Direction direction, Player& player, GamePhysics& physics) {
    if (!is_running()) {
        set_state(DuckStateType::RUNNING);
    }
    if (current_state->get_direction() != direction) {
        set_direction(direction);
    }
    execute(player, physics);
}

////

void DuckStateController::run_right(Player& player, GamePhysics& physics) {
    run(Direction::RIGHT, player, physics);
}
void DuckStateController::run_left(Player& player, GamePhysics& physics) {
    run(Direction::LEFT, player, physics);
}

void DuckStateController::jump(Player& player, GamePhysics& physics) {
    (void)player;
    (void)physics;
    if (!is_jumping() && !is_falling()) {
        set_state(DuckStateType::JUMPING);
    }
}
void DuckStateController::fall(Player& player, GamePhysics& physics) {
    (void)player;
    (void)physics;
    set_state(DuckStateType::FALLING);
}
void DuckStateController::crouch(Player& player, GamePhysics& physics) {
    (void)player;
    (void)physics;
    set_state(DuckStateType::CROUCHING);
}
void DuckStateController::slip(Player& player, GamePhysics& physics) {
    (void)player;
    (void)physics;
    set_state(DuckStateType::SLIPPING);
}
void DuckStateController::recoil(Player& player, GamePhysics& physics) {
    (void)player;
    (void)physics;
    set_state(DuckStateType::RECOILING);
}
void DuckStateController::plane(Player& player, GamePhysics& physics) {
    (void)player;
    (void)physics;
    set_state(DuckStateType::PLANNING);
    execute(player, physics);
}
void DuckStateController::die(Player& player) {
    (void)player;
    if (!is_dead()) {
        set_state(DuckStateType::DEAD);
    }
}
void DuckStateController::idle(Player& player) {
    (void)player;
    if (!is_idle()) {
        set_state(DuckStateType::IDLE);
    }
}
bool DuckStateController::is_jumping() { return is_in_state(DuckStateType::JUMPING); }
bool DuckStateController::is_running() { return is_in_state(DuckStateType::RUNNING); }
bool DuckStateController::is_falling() { return is_in_state(DuckStateType::FALLING); }
bool DuckStateController::is_dead() { return is_in_state(DuckStateType::DEAD); }
bool DuckStateController::is_idle() { return is_in_state(DuckStateType::IDLE); }

DuckStateType DuckStateController::get_state() { return current_state->get_id(); };
uint8_t DuckStateController::get_frame() { return current_state->get_frame(); };
Direction DuckStateController::get_direction() { return direction; }
DuckStateController::~DuckStateController() {}
