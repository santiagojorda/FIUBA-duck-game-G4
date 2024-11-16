#include "cowboy_gun.h"

#include "../../common/weapons_id.h"

CowboyGun::CowboyGun(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::LARGE) {
    this->set_texture_id(WEAPONS_ID_H::PISTOLA_COWBOY_ID);
}

ListProjectiles CowboyGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}