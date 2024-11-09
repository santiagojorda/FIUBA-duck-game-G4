#include "dueling_gun.h"

DuelingGun::DuelingGun() : Gun(MAX_AMMO) {}

ListProjectiles DuelingGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}