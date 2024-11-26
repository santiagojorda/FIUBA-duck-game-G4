#include "cowboy_gun.h"

#include <functional>

#include "../projectiles/bullet.h"

gun_config cowboy_config = {WeaponTextureID::COWBOY_GUN, 6, ShootingRecoil::NONE,
                            ProjectileRange::LARGE,      1, 1};

CowboyGun::CowboyGun(const Coordinate& _coordinate):
        Gun(cowboy_config, _coordinate), blocked(false) {}

void CowboyGun::trigger(ListProjectiles& projectiles) {
    if (!this->blocked) {
        for (int i = 0; i < cowboy_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(std::make_shared<Bullet>(
                        this->projectile_range, this->get_coordinate(), this->get_direction(), 0));
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
