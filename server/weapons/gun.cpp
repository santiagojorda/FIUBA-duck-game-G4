#include "gun.h"

#include <iostream>


Gun::Gun(const WeaponTextureID& _texture_id, const uint8_t& _max_ammo,
         const ShootingRecoil& _recoil, const ProjectileRange& _projectile_range,
         const Coordinate& _coordinate, uint8_t _daley_shoot):
        Positionable((uint8_t)_texture_id, _coordinate),
        Directionable(Direction::RIGHT),
        max_ammo(_max_ammo),
        ammo(_max_ammo),
        dispersion(INITIAL_DISPERSION),
        recoil(_recoil),
        projectile_range(_projectile_range),
        delay_counter(_daley_shoot)
        {}

Gun::Gun(const gun_config& _config, const Coordinate& _coordinate) : 
        Positionable((uint8_t)_config.id, _coordinate),
        Directionable(Direction::RIGHT),
        max_ammo(_config.max_ammo),
        ammo(_config.max_ammo),
        dispersion(INITIAL_DISPERSION),
        recoil(_config.recoil),
        projectile_range(_config.range),
        delay_counter(_config.daley_shoot)
        {}

void Gun::equip(Inventory& inventory) { inventory.equip(shared_from_this()); };

uint8_t Gun::get_max_ammo() { return max_ammo; }

uint8_t Gun::get_ammo() { return ammo; }

void Gun::trigger_out(ListProjectiles& projectiles) { 
        (void)projectiles;
        this->delay_counter.reset_count(); 
}

void Gun::trigger(ListProjectiles& projectiles){
        (void)projectiles;
}

ShootingRecoil Gun::get_recoil() { return this->recoil; }

Gun::~Gun() {}
