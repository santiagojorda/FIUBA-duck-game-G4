#include "projectile.h"

Projectile::Projectile(const uint8_t& texture_id, ProjectileRange _range_tiles,
                       Coordinate _coordinate, const Direction& _direction):
        Positionable(texture_id, _coordinate),  // deberia ser lanzado desde la posicion del player
        range_tiles(_range_tiles),
        direction(_direction) {}

void Projectile::update(GamePhysics& physics) { 
    (void)physics;
}
