#include "positionable.h"


Positionable::Positionable(): coordinates(0, 0, 0, 0) {}

Coordinate Positionable::get_coordinate() const { return this->coordinates; }


Positionable::~Positionable() {}
