#include "duck_state_controller.h"

#include <iostream>

#include "player.h"

DuckStateController::DuckStateController(const uint8_t& _player_id):
        states(_player_id), current_state(nullptr) {
    set_state(DuckStateType::IDLE);
    direction = current_state->get_direction();
}

void DuckStateController::set_state(const DuckStateType& new_state) {
    if (current_state) {
        current_state->finish();
    }
    current_state = states.get(new_state);
    if (current_state) {
        current_state->start();
    } else {
        std::cout << "No hay estado" << std::endl;
    }
}

void DuckStateController::set_direction(const Direction& new_direction) {
    if (new_direction != current_state->get_direction()) {
        direction = new_direction;
        current_state->set_direction(direction);
    }
}

void DuckStateController::update(Player& player, GamePhysics& physics) {
    if (current_state) {
        current_state->update(player, physics);
    }
};

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

bool DuckStateController::is_in_state(DuckStateType state) {
    return current_state && current_state->get_id() == state;
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
