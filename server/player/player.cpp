#include "player.h"

#include <iostream>

#include "../guns/gun.h"

const int SPEED = 1;

Player::Player() {}

Player::Player(uint8_t _id): id(_id) {}

uint8_t Player::get_id() const { return this->id; }

void Player::translate() {}

void Player::looks_right() { look_direction = Direction::RIGHT; }
void Player::looks_left() { look_direction = Direction::LEFT; }
void Player::looks_up() { look_direction = Direction::UP; }

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

Gun* Player::get_gun() { return inventory.get_gun(); }
Armor* Player::get_armor() { return inventory.get_armor(); }
Helmet* Player::get_helmet() { return inventory.get_helmet(); }

Inventory& Player::get_inventory() { return inventory; }
Direction Player::get_direction() { return look_direction; }

Player::~Player() { Positionable::~Positionable(); }
