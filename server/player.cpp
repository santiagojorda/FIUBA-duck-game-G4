#include "player.h"

const int SPEED = 1;


Player::Player(uint8_t& _id) : id(_id), Positionable() {}

void Player::translate(){
    /*que hacmeos aca?*/
}

void Player::translate_x() {  
  this->coordinates += Coordinate(2, 0, 0, 0) * SPEED;
}
void  Player::translate_y(){
  this->coordinates += Coordinate(0, 2, 0, 0) * SPEED;
}


Player::~Player(){

}
