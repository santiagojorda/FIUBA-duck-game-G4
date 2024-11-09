#include "ak_47.h"

AK47::AK47() : Gun(MAX_AMMO, ShootingRecoil::SHORT, ProjectileRange::MEDIUM)  {}

ListProjectiles AK47::shoot(Coordinate& shooter_position) {
    (void)shooter_position;    
    return ListProjectiles();
}