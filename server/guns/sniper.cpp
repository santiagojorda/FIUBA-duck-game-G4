#include "sniper.h"

Sniper::Sniper() : 
    Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::MAX)
    {}

ListProjectiles Sniper::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}