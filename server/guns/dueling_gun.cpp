#include "dueling_gun.h"

#include "../../common/weapons_id.h"

DuelingGun::DuelingGun(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::VERY_SHORT) {

    this->set_texture_id(WEAPONS_ID_H::PISTOLA_DUELOS_ID);
}

ListProjectiles DuelingGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}
