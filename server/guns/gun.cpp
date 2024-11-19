#include "gun.h"


Gun::Gun(const WeaponTextureID& _texture_id, const uint8_t& _max_ammo,
         const ShootingRecoil& _recoil, const ProjectileRange& _projectile_range,
         const Coordinate& _coordinate):
        Positionable((uint8_t)_texture_id, _coordinate),
        max_ammo(_max_ammo),
        ammo(_max_ammo),
        recoil(_recoil),
        projectile_range(_projectile_range) {}

void Gun::equip(Inventory* inventory) { inventory->equip(this); };

uint8_t Gun::get_max_ammo() { return max_ammo; }
uint8_t Gun::get_ammo() { return ammo; }

ShootingRecoil Gun::get_recoil() { return this->recoil; }


ListProjectiles Gun::shoot(Coordinate& shooter_position, ShootingRecoil& _recoil) {
    _recoil = recoil;
    return shoot(shooter_position);
}

void Gun::translate() {}
void Gun::translate_x(int pasos) { (void)pasos; }
void Gun::translate_y(int pasos) { (void)pasos; }

Gun::~Gun() {}
