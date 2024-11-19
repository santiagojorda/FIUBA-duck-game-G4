#include "ground.h"

#define GROUND_TEXTURE_ID 99  // CAMBIAR

Ground::Ground(const Coordinate& _coordinate): Positionable(GROUND_TEXTURE_ID, _coordinate) {}

Ground::Ground(const Coordinate& _coordinate, const uint8_t& _texture_id, const uint8_t& map_id ) : Positionable(_texture_id, _coordinate) {
    this->id = map_id;
}
