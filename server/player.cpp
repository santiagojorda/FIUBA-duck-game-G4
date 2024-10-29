#include "player.h"

const int SPEED = 1;

Player::Player(uint8_t _id) : Positionable(), id(_id) {}

uint8_t Player::get_id() const { return this->id; }

Coordinate Player::get_coordinate() const {
    return this->coordinates;
}

void Player::translate() { /*que hacmeos aca?*/ }


void Player::translate_x() { this->coordinates += Coordinate(2, 0, 0, 0) * SPEED; }
void Player::translate_y() { this->coordinates += Coordinate(0, 2, 0, 0) * SPEED; }


Player::~Player() {Positionable::~Positionable();}
