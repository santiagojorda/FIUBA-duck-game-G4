#include "positionable.h"

Positionable::Positionable(): space(1, 11, 32, 32) {}  // DUMMY

Positionable::Positionable(const uint8_t& _texture_id, const Coordinate& _coordinate): texture_id(_texture_id), space(_coordinate) {}

Coordinate Positionable::get_coordinate() const { return this->space.get_coordinates(); }

Rectangle Positionable::get_rectangle() const { return this->space; }

uint8_t Positionable::get_id() { return id; }
uint8_t Positionable::get_texture_id() { return texture_id; }

Positionable::~Positionable() {}