#include "player.h"

#include <iostream>

#include "../guns/gun.h"

const int SPEED = 1;
#define RUN_STEP 10
#define JUMP_STEP -10
#define FALLING_STEP 10

Player::Player(): Statable(DuckState::IS_IDLE) {}
Player::Player(uint8_t _id): Statable(DuckState::IS_IDLE), id(_id) {}
Player::~Player() { Positionable::~Positionable(); }

void Player::looks_right() { look_direction = Direction::RIGHT; }
void Player::looks_left() { look_direction = Direction::LEFT; }
void Player::looks_up() { look_direction = Direction::UP; }

void Player::update() {

    frame++;

    if (frame >= duck_state_frames[state].max_frames) {
        switch (state) {
            case DuckState::IS_FALLING:
                reset();
                break;

            default:
                set_state(DuckState::IS_IDLE);
        }
    }
}

void Player::run_right() {
    set_state(DuckState::IS_RUNNING);
    translate_x(RUN_STEP);
}
void Player::run_left() {
    set_state(DuckState::IS_RUNNING);
    translate_x(-RUN_STEP);
}
void Player::jump() {
    set_state(DuckState::IS_JUMPING);
    translate_y(JUMP_STEP);
}
void Player::fall() {
    set_state(DuckState::IS_FALLING);
    translate_y(FALLING_STEP);
}
void Player::crouch() {
    set_state(DuckState::IS_CROUCHING);
    // translate_y(1); // esto no deberia moverse
}
void Player::slip() { set_state(DuckState::IS_SLIPPING); }
void Player::recoil() { set_state(DuckState::IS_RECOILING); }
void Player::plane() { set_state(DuckState::IS_PLANING); }
void Player::die() { set_state(DuckState::IS_DEAD); }

uint8_t Player::get_id() const { return this->id; }
Gun* Player::get_gun() { return inventory.get_gun(); }
Armor* Player::get_armor() { return inventory.get_armor(); }
Helmet* Player::get_helmet() { return inventory.get_helmet(); }
Inventory& Player::get_inventory() { return inventory; }
Direction Player::get_direction() { return look_direction; }

void Player::translate() {}
void Player::translate_x(int pasos) {  // cambiar la variable
    if (pasos > 0) {
        looks_right();
    } else if (pasos < 0) {
        looks_left();
    }

    Rectangle new_pos(this->space.get_coordinates() + Coordinate(pasos * SPEED, 0, 0, 0));
    this->space = new_pos;
}

void Player::translate_y(int pasos) {  // cambiar la variable
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
    // if(look_direction == Direction::LEFT){
    //     translate_x()
    // }
    // else{
    //     translate_x();
    // }

    // esto tiene que ser de forma iterativa -> stado

    (void)tiles;
}

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

// --------------------- STATE
