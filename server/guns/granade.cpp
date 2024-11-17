#include "granade.h"

#include "../../common/weapons_id.h"


Granade::Granade(): Gun(MAX_AMMO, ShootingRecoil::NONE, ProjectileRange::MEDIUM) {
     this->set_texture_id(WEAPONS_ID_H::GRANADA_ID);
}

ListProjectiles Granade::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}