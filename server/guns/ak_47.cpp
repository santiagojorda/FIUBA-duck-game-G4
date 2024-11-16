#include "ak_47.h"

AK47::AK47(Coordinate _coordinate): 
    Gun(MAX_AMMO, ShootingRecoil::SHORT, ProjectileRange::MEDIUM, _coordinate)
    {}

ListProjectiles AK47::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}