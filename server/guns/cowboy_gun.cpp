#include "cowboy_gun.h"

CowboyGun::CowboyGun() : 
    Gun(MAX_AMMO, ShootingRecoil::NONE ,ProjectileRange::LARGE)
{}

ListProjectiles CowboyGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}