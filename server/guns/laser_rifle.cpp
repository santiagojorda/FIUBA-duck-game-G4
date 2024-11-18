#include "laser_rifle.h"

#include "../../common/weapons_id.h"


LaserRifle::LaserRifle(const Coordinate& _coordinate):
        Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::VERY_LARGE, _coordinate) {
    this->set_texture_id(WEAPONS_ID_H::LASER_RIFLE_ID);
}

ListProjectiles LaserRifle::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}