#include "cowboy_gun.h"

#include <functional>

#include "../projectiles/bullet.h"

struct CowboyConfig {
    WeaponTextureID id = WeaponTextureID::COWBOY_GUN;
    uint8_t max_ammo = 6;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::LARGE;
    uint8_t count_projectiles_x_shoot = 1;
};
CowboyConfig cowboy_config;

CowboyGun::CowboyGun(const Coordinate& _coordinate):
        Gun(cowboy_config.id, cowboy_config.max_ammo, cowboy_config.recoil, cowboy_config.range,
            _coordinate),
        blocked(false) {}

void CowboyGun::trigger(ListProjectiles& projectiles) {
    if (!this->blocked) {
        for (int i = 0; i < cowboy_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(new Bullet(this->projectile_range, this->get_coordinate(),
                                           this->get_direction(), 0));
                this->ammo--;
            }
        }
        this->blocked = true;
    }
}

void CowboyGun::trigger_out(ListProjectiles& projectiles) {
    (void)projectiles;
    this->blocked = false;
}


CowboyGun::~CowboyGun() {}
