#include "gun.h"

#include <iostream>


Gun::Gun(const WeaponTextureID& _texture_id, const uint8_t& _max_ammo,
         const ShootingRecoil& _recoil, const ProjectileRange& _projectile_range,
         const Coordinate& _coordinate):
        Positionable((uint8_t)_texture_id, _coordinate),
        max_ammo(_max_ammo),
        ammo(_max_ammo),
        recoil(_recoil),
        projectile_range(_projectile_range),
        direction(Direction::RIGHT)
        {}

void Gun::equip(Inventory* inventory) { inventory->equip(this); };

uint8_t Gun::get_max_ammo() { return max_ammo; }

uint8_t Gun::get_ammo() { return ammo; }

void Gun::trigger_out(ListProjectiles& projectiles){
        (void)projectiles;
}

void Gun::trigger(ListProjectiles& projectiles){
        (void)projectiles;
}

Direction Gun::get_direction() { return direction; }

void Gun::set_direction(const Direction& new_direction) { 
        if(direction != new_direction){
                std::cout << "arma cambio de direccion" << std::endl;
                direction = new_direction; 
        }
}

ShootingRecoil Gun::get_recoil() { return this->recoil; }

Gun::~Gun() {}
