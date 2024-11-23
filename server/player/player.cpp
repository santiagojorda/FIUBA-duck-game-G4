#include "player.h"

#include <iostream>

#include "../../common/state_duck.h"
#include "../guns/gun.h"

const int SPEED = 1;
#define RUN_STEP 10
#define JUMP_STEP -40
#define FALLING_STEP 1

Player::Player(uint8_t _id): Positionable(_id, _id, Coordinate(10, 10, 32, 32)), state(id) {}

Player::~Player() { Positionable::~Positionable(); }

void Player::update(GamePhysics& physics) { state.update(*this, physics); }

void Player::log_action(const std::string& action) {
    std::cout << "Player " << int(id) << " " << action << std::endl;
}

void Player::run_right(GamePhysics& physics) { state.run_right(*this, physics); }
void Player::run_left(GamePhysics& physics) { state.run_left(*this, physics); }
void Player::jump(GamePhysics& physics) { state.jump(*this, physics); }
void Player::fall(GamePhysics& physics) { state.fall(*this, physics); }
void Player::crouch(GamePhysics& physics) { state.crouch(*this, physics); }
void Player::slip(GamePhysics& physics) { state.slip(*this, physics); }
void Player::recoil(GamePhysics& physics) { state.recoil(*this, physics); }
void Player::plane(GamePhysics& physics) { state.plane(*this, physics); }
void Player::idle() { state.idle(*this); }
void Player::die() {
    health = 0;
    state.die(*this);
}

uint8_t Player::get_id() const { return this->id; }
Gun* Player::get_gun() { return inventory.get_gun(); }
Armor* Player::get_armor() { return inventory.get_armor(); }
Helmet* Player::get_helmet() { return inventory.get_helmet(); }
Inventory& Player::get_inventory() { return inventory; }
Direction Player::get_direction() { return state.get_direction(); }

void Player::adjust_position_to_floor(Positionable* floor) {
    if (floor) {

        int player_bottom = space.get_y_max();
        Rectangle floor_points = floor->get_rectangle();
        int floor_top = floor_points.get_y_min();
        int difference = player_bottom - floor_top;

        if (difference < 1) {
            translate_y(-(difference + 1));
        } else {
            translate_y(-(difference - 1));
        }
    }
}

void Player::translate_x(int pasos) {
    int boost_speed = 1;
    Positionable::translate_x(pasos*boost_speed);
}

void Player::translate_y(int pasos) {
    int boost_speed = 1; // si queremos 
    Positionable::translate_y(pasos*boost_speed);
}

Player& Player::operator=(const Player& _other) {
    this->id = _other.id;
    this->space = _other.space;
    return *this;
}

void Player::equip(Equippable* item) { inventory.equip(item); }
void Player::move_back(ShootingRecoil tiles) { (void)tiles; }

bool Player::is_jumping() { return state.is_jumping(); }
bool Player::is_running() { return state.is_running(); }
bool Player::is_falling() { return state.is_falling(); }
bool Player::is_idle() { return state.is_idle(); }
bool Player::is_dead() { return state.is_dead(); }

DuckStateType Player::get_state() { return state.get_state(); }

uint8_t Player::get_frame() { return state.get_frame(); }

void Player::shoot(ListProjectiles& projectiles, const   ModeShoot& mode) {
    Gun* gun = inventory.get_gun();
    if (!gun) {
        return;
    }
    ShootingRecoil recoil = gun->get_recoil();
    switch (mode)  {
        case ModeShoot::TRIGGER:
            gun->trigger(projectiles, state.get_direction());
            break;
        case ModeShoot::TRIGGER_OUT:
            gun->trigger_out(projectiles, state.get_direction());
            break;
        default:
            break;
    }
    if ((int)recoil > 0) {  // is there recoil? yes -> it could be a function
        move_back(recoil);
    }
}
