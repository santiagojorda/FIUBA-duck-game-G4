#include "player.h"

const int SPEED = 1;


Player::Player(uint8_t _id): id(_id) {}

uint8_t Player::get_id() const { return this->id; }


void Player::translate() { /*que hacmeos aca?*/ }


void Player::translate_x(int pasos) { this->coordinates += Coordinate(pasos, 0, 0, 0) * SPEED; }
void Player::translate_y(int pasos) { this->coordinates += Coordinate(0, 2, 0, 0) * SPEED; }


Player::~Player() {}
