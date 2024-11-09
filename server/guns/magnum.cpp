#include "magnum.h"

Magnum::Magnum() : 
    Gun(MAX_AMMO, ShootingRecoil::SHORT, ProjectileRange::VERY_LARGE)
    {}

ListProjectiles Magnum::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}