#include "sniper.h"

#include "../../common/weapons_id.h"

Sniper::Sniper(const Coordinate& _coordinate): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::MAX, _coordinate) {
    this->set_texture_id(WEAPONS_ID_H::SNIPER_ID);
}

ListProjectiles Sniper::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}