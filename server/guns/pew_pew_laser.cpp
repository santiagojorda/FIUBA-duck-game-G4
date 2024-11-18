#include "pew_pew_laser.h"

#include "../../common/weapons_id.h"


PewPewLaser::PewPewLaser(Coordinate _coordinate):
        Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::EXTREME, _coordinate) {
    this->set_texture_id(WEAPONS_ID_H::PEW_PEW_LASER_ID);
}

ListProjectiles PewPewLaser::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}