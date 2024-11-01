#include "player.h"

const int SPEED = 1;

Player::Player() {}

Player::Player(uint8_t _id): Positionable(), id(_id) {}

uint8_t Player::get_id() const { return this->id; }

void Player::translate() { /*que hacmeos aca?*/ }

void Player::translate_x(int pasos) {
    Rectangle new_pos(this->space.get_coordinates() + Coordinate(pasos, 0, 0, 0) * SPEED);
    this->space = new_pos;
}

void Player::translate_y(int pasos) {
    Rectangle new_pos(this->space.get_coordinates() + Coordinate(0, pasos, 0, 0) * SPEED);
    this->space = new_pos;
}

Player::~Player() { Positionable::~Positionable(); }
