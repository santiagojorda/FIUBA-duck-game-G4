#include "projectile.h"

Projectile::Projectile(uint8_t _range_tiles) : 
    Positionable(), // dummy
    range_tiles(_range_tiles)
    {}

Projectile::Projectile(uint8_t _range_tiles, Coordinate _coordinate) : 
    Positionable(_coordinate), // deberia ser lanzado desde la posicion del player
    range_tiles(_range_tiles)
    {}
