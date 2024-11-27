#include "sniper.h"

#include "../projectiles/bullet.h"


gun_config sniper_config{WeaponTextureID::SNIPER, 6, ShootingRecoil::NONE,
                         ProjectileRange::MAX,    1, 20};

Sniper::Sniper(const Coordinate& _coordinate): Gun(sniper_config, _coordinate), blocked(false) {}

void Sniper::trigger(ListProjectiles& projectiles) {
    if (!this->blocked) {
        for (int i = 0; i < sniper_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(std::make_shared<Bullet>(
                        this->projectile_range, this->get_coordinate(), this->get_direction(), 5));
                this->ammo--;
            }
        }
        this->blocked = true;
    }
}

void Sniper::trigger_out(ListProjectiles& projectiles) {
    (void)projectiles;
    this->blocked = false;
}

Sniper::~Sniper() {}
