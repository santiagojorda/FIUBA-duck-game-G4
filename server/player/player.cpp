#include "player.h"

#include <iostream>

const int SPEED = 1;

Player::Player() : inventory() {}

Player::Player(uint8_t _id): Positionable(), id(_id) {}

uint8_t Player::get_id() const { return this->id; }

void Player::translate() { /*que hacmeos aca?*/
}

void Player::translate_x(int pasos) {
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

void Player::equip(Equippable* item){
    inventory.equip(item);
}

void Player::move_back(uint8_t tiles){
    (void)tiles;
}

Gun* Player::get_gun() { return inventory.get_gun(); }
Armor* Player::get_armor() {return inventory.get_armor();}
Helmet* Player::get_helmet() {return inventory.get_helmet();}



Player::~Player() { Positionable::~Positionable(); }
