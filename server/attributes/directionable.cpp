#include "directionable.h"



Directionable::Directionable(const Direction& _diretion) : direction(_diretion)  {}

Direction Directionable::get_direction() const { return this->direction; }

void Directionable::set_direction(const Direction& new_diretion){
    this->direction = new_diretion;
}

int  Directionable::get_direction_int() {
    return (this->direction == Direction::RIGHT) ? 1 : -1; //refactor
}

Directionable::~Directionable() {}

