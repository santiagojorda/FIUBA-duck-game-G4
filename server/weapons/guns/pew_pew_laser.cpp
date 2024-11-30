#include "pew_pew_laser.h"

#include "../projectiles/bullet.h"


gun_config pew_pew_laser_config{WeaponTextureID::PEW_PEW_LASER, 12, ShootingRecoil::NONE,
                                ProjectileRange::EXTREME,       1,  10};


PewPewLaser::PewPewLaser(Coordinate _coordinate):
        Gun(pew_pew_laser_config, _coordinate), blocked(false) {}

void PewPewLaser::trigger(ListProjectiles& projectiles, const uint8_t& player_id) {
    if (!this->blocked) {
        for (int i = 0; i < pew_pew_laser_config.count_projectiles_x_shoot; i++) {
            if (this->ammo > 0) {
                projectiles.add(std::make_shared<Bullet>(
                        this->projectile_range, this->get_coordinate(), this->get_direction(), 0, player_id));
                this->ammo--;
            }
        }
        this->blocked = true;
    }
}


void PewPewLaser::trigger_out(ListProjectiles& projectiles, const uint8_t& player_id) {
    Gun::trigger_out(projectiles, player_id);
    this->blocked = false;
}


PewPewLaser::~PewPewLaser() {}
