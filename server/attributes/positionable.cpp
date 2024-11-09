#include "positionable.h"

Positionable::Positionable(): space(1, 11, 32, 32) {}

Positionable::Positionable(Coordinate& _coordinate): space(_coordinate) {}

Coordinate Positionable::get_coordinate() const { return this->space.get_coordinates(); }

Rectangle Positionable::get_rectangle() const { return this->space; }

Positionable::~Positionable() {}