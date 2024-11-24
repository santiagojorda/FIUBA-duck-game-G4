#include "shotgun.h"

#include "../projectiles/bullet.h"


struct ShotgunConfig {
    WeaponTextureID id = WeaponTextureID::SHOTGUN;
    uint8_t max_ammo = 2;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::LARGE;
    uint8_t count_projectiles_x_shoot = 1;
};
ShotgunConfig shotgun_config;

Shotgun::Shotgun(const Coordinate& _coordinate):
        Gun(shotgun_config.id, shotgun_config.max_ammo, shotgun_config.recoil, shotgun_config.range,
            _coordinate),
        reloaded(false) {}


void Shotgun::trigger(ListProjectiles& projectiles) {
    if (this->reloaded) {
        this->reloaded = false;
    } else {
        for (int i = 0; i < shotgun_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(new Bullet(this->projectile_range, this->get_coordinate(),
                                           this->get_direction(), 20));
                this->ammo--;
            }
        }
        this->reloaded = true;
    }
}

Shotgun::~Shotgun() {}
