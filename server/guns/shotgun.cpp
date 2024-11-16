#include "shotgun.h"

#include "../../common/weapons_id.h"


Shotgun::Shotgun(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::LARGE) {
    this->set_texture_id(WEAPONS_ID_H::ESCOPETA_ID);
}

ListProjectiles Shotgun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}