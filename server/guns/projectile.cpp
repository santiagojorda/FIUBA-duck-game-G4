#include "projectile.h"

Projectile::Projectile(): range_tiles(ProjectileRange::NONE) {}

Projectile::Projectile(ProjectileRange _range_tiles) : 
    Positionable(), // dummy
    range_tiles(_range_tiles)
    {}

Projectile::Projectile(ProjectileRange _range_tiles, Coordinate _coordinate) : 
    Positionable(_coordinate), // deberia ser lanzado desde la posicion del player
    range_tiles(_range_tiles)
    {}

void Projectile::set_projectile_range(ProjectileRange _range_tiles){
    range_tiles = _range_tiles;
}
