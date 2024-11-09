#include "magnum.h"

Magnum::Magnum() : Gun(MAX_AMMO) {}

ListProjectiles Magnum::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}