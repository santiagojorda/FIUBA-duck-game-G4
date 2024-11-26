#include "pew_pew_laser.h"

#include "../projectiles/bullet.h"


gun_config pew_pew_laser_config {WeaponTextureID::PEW_PEW_LASER, 12, ShootingRecoil::NONE,
                           ProjectileRange::EXTREME,  1,  10};


PewPewLaser::PewPewLaser(Coordinate _coordinate):
        Gun(pew_pew_laser_config,  _coordinate),
        blocked(false) {}

void PewPewLaser::trigger(ListProjectiles& projectiles) {
    if (!this->blocked) {
        for (int i = 0; i < pew_pew_laser_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(std::make_shared<Bullet>(
                        this->projectile_range, this->get_coordinate(), this->get_direction(), 0));
                this->ammo--;
            }
        }
        this->blocked = true;
    }
}


void PewPewLaser::trigger_out(ListProjectiles& projectiles) {
    (void)projectiles;
    this->blocked = false;
}


PewPewLaser::~PewPewLaser() {}
