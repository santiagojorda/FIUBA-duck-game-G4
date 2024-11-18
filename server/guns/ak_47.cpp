#include "ak_47.h"

#include "../../common/weapons_id.h"


#define MAX_AMMO 30


AK47::AK47(const Coordinate& _coordinate):
        Gun(MAX_AMMO, ShootingRecoil::SHORT, ProjectileRange::MEDIUM, _coordinate) {
    this->set_texture_id(WEAPONS_ID_H::AK_47_ID);
}

ListProjectiles AK47::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}