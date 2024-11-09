#include "banana.h"

Banana::Banana() : 
    Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::MEDIUM),  // no me gusta se define 2 veces
    Projectile()
    {}

ListProjectiles Banana::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    set_projectile_range(projectile_range);
    return ListProjectiles();
}