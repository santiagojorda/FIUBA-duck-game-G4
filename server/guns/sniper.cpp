#include "sniper.h"

Sniper::Sniper() : Gun(MAX_AMMO) {}

ListProjectiles Sniper::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}