#include "gun.h"

Gun::Gun(uint8_t _ammo, ShootingRecoil _recoil, ProjectileRange _projectile_range):
        ammo(_ammo), recoil(_recoil), projectile_range(_projectile_range) {}

Gun::Gun(uint8_t _ammo, ShootingRecoil _recoil, ProjectileRange _projectile_range, Coordinate _coordinate):
    Positionable(_coordinate),
    ammo(_ammo), 
    recoil(_recoil), 
    projectile_range(_projectile_range)
    {}

void Gun::equip(Inventory* inventory) { inventory->equip(this); };

uint8_t Gun::get_ammo() { return ammo; }

ListProjectiles Gun::shoot(Coordinate& shooter_position, ShootingRecoil& _recoil) {
    _recoil = recoil;
    return shoot(shooter_position);
}
void Gun::translate() {} 
void Gun::translate_x(int pasos) {(void)pasos;} 
void Gun::translate_y(int pasos) {(void)pasos;} 