#include "box.h"

#define GROUND_TEXTURE_ID 99  // CAMBIAR

Box::Box(const Coordinate& _coordinate, const uint8_t& _texture_id): Positionable(_texture_id, _coordinate) {}
