#include "banana.h"

Banana::Banana() : Gun(MAX_AMMO), Projectile(MAX_RANGE_TILES) {}

ListProjectiles Banana::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}