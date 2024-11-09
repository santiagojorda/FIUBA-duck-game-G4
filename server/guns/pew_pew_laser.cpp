#include "pew_pew_laser.h"

PewPewLaser::PewPewLaser() : 
    Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::EXTREME)
    {}

ListProjectiles PewPewLaser::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}