#include "pew_pew_laser.h"

#include "../../common/weapons_id.h"


PewPewLaser::PewPewLaser(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::EXTREME) {
    this->set_texture_id(WEAPONS_ID_H::PEW_PEW_LASER_ID);
}

ListProjectiles PewPewLaser::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}