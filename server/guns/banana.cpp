#include "banana.h"

#include "../../common/weapons_id.h"


Banana::Banana():
        Gun(MAX_AMMO, ShootingRecoil::NONE,
            ProjectileRange::MEDIUM) {  // no me gusta se define 2 vece 
    this->set_texture_id(WEAPONS_ID_H::BANANA_ID);
}

ListProjectiles Banana::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}