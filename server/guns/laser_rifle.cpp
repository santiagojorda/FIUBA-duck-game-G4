#include "laser_rifle.h"

LaserRifle::LaserRifle() : 
    Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::VERY_LARGE)
    {}

ListProjectiles LaserRifle::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}