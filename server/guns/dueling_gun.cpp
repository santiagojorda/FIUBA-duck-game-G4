#include "dueling_gun.h"

DuelingGun::DuelingGun(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::VERY_SHORT) {}

ListProjectiles DuelingGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}