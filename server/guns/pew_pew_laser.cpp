#include "pew_pew_laser.h"

#include <functional>

#include "../../common/weapons_id.h"

#include "bullet.h"

struct PewPewLaserConfig {
    WeaponTextureID id = WeaponTextureID::PEW_PEW_LASER;
    uint8_t max_ammo = 12;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::EXTREME;
    uint8_t count_projectiles_x_shoot = 1;
};
PewPewLaserConfig pew_pew_laser_config;

PewPewLaser::PewPewLaser(Coordinate _coordinate):
        Gun(pew_pew_laser_config.id, pew_pew_laser_config.max_ammo, pew_pew_laser_config.recoil,
            pew_pew_laser_config.range, _coordinate) {}

ListProjectiles PewPewLaser::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}

void PewPewLaser::shoot(ListProjectiles& projectiles, Direction direction) {
    (void)direction;
    (void)projectiles;
    // for (int i = 0; i < pew_pew_laser_config.count_projectiles_x_shoot; i++) {
    //     if (this->ammo > 0) {
    //         projectiles.add(new Bullet(this->projectile_range, this->get_coordinate()));
    //         this->ammo--;
    //     }
    // }
}
