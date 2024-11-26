#include "sniper.h"

#include "../projectiles/bullet.h"


struct SniperConfig {
    WeaponTextureID id = WeaponTextureID::SNIPER;
    uint8_t max_ammo = 6;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::MAX;
    uint8_t count_projectiles_x_shoot = 1;
};
SniperConfig sniper_config;

Sniper::Sniper(const Coordinate& _coordinate):
        Gun(sniper_config.id, sniper_config.max_ammo, sniper_config.recoil, sniper_config.range,
            _coordinate),
        blocked(false) {}

void Sniper::trigger(ListProjectiles& projectiles) {
    if (!this->blocked) {
        for (int i = 0; i < sniper_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(std::make_shared<Bullet>(this->projectile_range, this->get_coordinate(),
                                           this->get_direction(), 5));
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
