#include "positionable.h"

Positionable::Positionable(): space(0, 0, 0, 0) {}

Coordinate Positionable::get_coordinate() const { return this->space.get_coordinates(); }

Rectangle Positionable::get_rectangle() const { return this->space; }

Positionable::~Positionable() {}
