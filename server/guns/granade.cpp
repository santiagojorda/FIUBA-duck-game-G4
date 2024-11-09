#include "granade.h"

Granade::Granade() : Gun(MAX_AMMO), Projectile(MAX_RANGE_TILES) {}

ListProjectiles Granade::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}