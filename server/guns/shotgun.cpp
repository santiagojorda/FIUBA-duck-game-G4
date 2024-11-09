#include "shotgun.h"

Shotgun::Shotgun() : Gun(MAX_AMMO) {}

ListProjectiles Shotgun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}