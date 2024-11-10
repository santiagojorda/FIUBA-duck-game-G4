#include "shotgun.h"

Shotgun::Shotgun(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::LARGE) {}

ListProjectiles Shotgun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}