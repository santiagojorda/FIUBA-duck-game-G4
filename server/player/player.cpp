#include "player.h"

#include <iostream>

#include "../../common/state_duck.h"
#include "../guns/gun.h"

const int SPEED = 1;
#define RUN_STEP 10
#define JUMP_STEP -10
#define FALLING_STEP 1

Player::Player(uint8_t _id): Positionable(_id, _id, Coordinate(10, 10, 32, 32)), state(*this) {}

Player::~Player() { Positionable::~Positionable(); }

void Player::looks_right() { look_direction = Direction::RIGHT; }
void Player::looks_left() { look_direction = Direction::LEFT; }
void Player::looks_up() { look_direction = Direction::UP; }

void Player::update(GamePhysics& physics) { 
    state.update(*this, physics); 
}

void Player::log_action(const std::string& action) { std::cout << "Player " << int(id) << " " << action << std::endl; }

void Player::run_right(GamePhysics& physics) { state.run_right(*this, physics); }
void Player::run_left(GamePhysics& physics) { state.run_left(*this, physics); }
void Player::jump(GamePhysics& physics) { state.jump(*this, physics); }
void Player::fall(GamePhysics& physics) { state.fall(*this, physics); }
void Player::crouch(GamePhysics& physics) { state.crouch(*this, physics); }
void Player::slip(GamePhysics& physics) { state.slip(*this, physics); }
void Player::recoil(GamePhysics& physics) { state.recoil(*this, physics); }
void Player::plane(GamePhysics& physics) { state.plane(*this, physics); }
void Player::idle() { state.idle(); }
void Player::die() {
    health = 0;
    state.die();
}

uint8_t Player::get_id() const { return this->id; }
Gun* Player::get_gun() { return inventory.get_gun(); }
Armor* Player::get_armor() { return inventory.get_armor(); }
Helmet* Player::get_helmet() { return inventory.get_helmet(); }
Inventory& Player::get_inventory() { return inventory; }
Direction Player::get_direction() { return look_direction; }

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

void Player::translate() {}
void Player::translate_x(int pasos) { 
    if (pasos > 0) {
        looks_right();
    } else if (pasos < 0) {
        looks_left();
    }

    Rectangle new_pos(this->space.get_coordinates() + Coordinate(pasos * SPEED, 0, 0, 0));
    this->space = new_pos;
}

void Player::translate_y(int pasos) { 
    Rectangle new_pos(this->space.get_coordinates() + Coordinate(0, pasos * SPEED, 0, 0));
    this->space = new_pos;
}

Player& Player::operator=(const Player& _other) {
    this->id = _other.id;
    this->space = _other.space;
    return *this;
}

void Player::equip(Equippable* item) { inventory.equip(item); }
void Player::move_back(ShootingRecoil tiles) {
    (void)tiles;
}

bool Player::is_jumping() { return state.is_jumping(); }
bool Player::is_dead() { return state.is_dead(); }
bool Player::is_running() { return state.is_running(); }

DuckStateType Player::get_state() { return state.get_state(); }
uint8_t Player::get_frame() { return state.get_frame(); }

ListProjectiles Player::shoot() {
    Gun* gun = inventory.get_gun();
    if (!gun) {
        return ListProjectiles();
    }

    Coordinate actual_position = get_coordinate();
    ShootingRecoil recoil;
    ListProjectiles projectiles = gun->shoot(actual_position, recoil);
    if ((int)recoil > 0) {  // is there recoil? yes -> it could be a function
        move_back(recoil);
    }
    return projectiles;
}

