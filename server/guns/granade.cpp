#include "granade.h"

Granade::Granade(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::MEDIUM), Projectile() {}

ListProjectiles Granade::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    set_projectile_range(range_tiles);
    return ListProjectiles();
}