#include "granade.h"

#include "../../common/weapons_id.h"


Granade::Granade(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::MEDIUM), Projectile() {
    // this->set_texture_id(WEAPONS_ID_H::GRANADA_ID);
}

ListProjectiles Granade::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    set_projectile_range(range_tiles);
    return ListProjectiles();
}