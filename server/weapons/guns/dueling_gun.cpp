#include "dueling_gun.h"

#include <functional>

#include "../projectiles/bullet.h"

struct DuelingConfig {
    WeaponTextureID id = WeaponTextureID::DUELING_GUN;
    uint8_t max_ammo = 1;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::VERY_SHORT;
    uint8_t count_projectiles_x_shoot = 1;
};
DuelingConfig dueling_config;

DuelingGun::DuelingGun(const Coordinate& _coordinate):
        Gun(dueling_config.id, dueling_config.max_ammo, dueling_config.recoil, dueling_config.range,
            _coordinate) {}

void DuelingGun::trigger(ListProjectiles& projectiles) {
    (void)projectiles;
    for (int i = 0; i < dueling_config.count_projectiles_x_shoot; i++) {
        if (this->ammo > 0) {
            projectiles.add(new Bullet(this->projectile_range, this->get_coordinate(),
                                       this->get_direction(), 0));
            this->ammo--;
        }
    }
}


DuelingGun::~DuelingGun() {}
