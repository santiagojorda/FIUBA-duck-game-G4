#include "laser_rifle.h"

#include "../projectiles/bullet_bounce.h"


struct LaserConfig {
    WeaponTextureID id = WeaponTextureID::LASER_RIFLE;
    uint8_t max_ammo = 10;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::VERY_LARGE;
    uint8_t count_projectiles_x_shoot = 1;
};
LaserConfig laser_config;


LaserRifle::LaserRifle(const Coordinate& _coordinate):
        Gun(laser_config.id, laser_config.max_ammo, laser_config.recoil, laser_config.range,
            _coordinate) {}

void LaserRifle::trigger(ListProjectiles& projectiles) {
    (void)projectiles;

    for (int i = 0; i < laser_config.count_projectiles_x_shoot; i++) {
        if (this->ammo > 0) {
            //  projectiles.add(std::make_shared<BulletBounce>(this->projectile_range this->get_coordinate(),
            //  this->get_direction(), 0));
            this->ammo--;
        }
    }
}


LaserRifle::~LaserRifle() {}
