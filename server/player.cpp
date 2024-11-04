#include "player.h"

#include <iostream>

const int SPEED = 1;

Player::Player() {}

Player::Player(uint8_t _id): Positionable(), id(_id) {}

uint8_t Player::get_id() const { return this->id; }

void Player::translate() { /*que hacmeos aca?*/ }

void Player::translate_x(int pasos) {
    Rectangle new_pos(this->space.get_coordinates() + Coordinate(pasos * SPEED, 0, 0, 0));
    // std::cout << new_pos.get_coordinates() << std::endl;
    this->space = new_pos;
}

void Player::translate_y(int pasos) {
    Rectangle new_pos(this->space.get_coordinates() + Coordinate(0, pasos * SPEED, 0, 0));
    // std::cout << new_pos.get_coordinates() << std::endl;
    this->space = new_pos;
}

Player& Player::operator=(const Player& _other) {
    this->id = _other.id;
    this->space = _other.space;
    return *this;
}

Player::~Player() { Positionable::~Positionable(); }
