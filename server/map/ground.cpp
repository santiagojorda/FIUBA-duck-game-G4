#include "ground.h"

#define GROUND_TEXTURE_ID 99  // CAMBIAR

Ground::Ground(const Coordinate& _coordinate): Positionable(GROUND_TEXTURE_ID, _coordinate) {}