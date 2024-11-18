#include "magnum.h"

#include "../../common/weapons_id.h"

Magnum::Magnum(const Coordinate& _coordinate):
        Gun(MAX_AMMO, ShootingRecoil::SHORT, ProjectileRange::VERY_LARGE, _coordinate) {
    this->set_texture_id(WEAPONS_ID_H::MAGNUM_ID);
}

ListProjectiles Magnum::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}