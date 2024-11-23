#include "ak_47.h"

#include "../guns_projectiles/bullet.h"

struct AKConfig {
    WeaponTextureID id = WeaponTextureID::AK_47;
    uint8_t max_ammo = 30;
    ShootingRecoil recoil = ShootingRecoil::SHORT;
    ProjectileRange range = ProjectileRange::MEDIUM;
    uint8_t count_projectiles_x_shoot = 1;
};
AKConfig ak_config;

AK47::AK47(const Coordinate& _coordinate):
        Gun(ak_config.id, ak_config.max_ammo, ak_config.recoil, ak_config.range, _coordinate) {}

void AK47::trigger(ListProjectiles& projectiles, Direction direction) {
    (void)direction;
    this->dispersion++;
    for (int i = 0; i < ak_config.count_projectiles_x_shoot; i++) {
        if (this->ammo > 0) {
            projectiles.add(new Bullet(this->projectile_range, this->get_coordinate(), direction,
                                       this->dispersion));
            this->ammo--;
        }
    }
}

void AK47::trigger_out(ListProjectiles& projectiles, Direction direction) {
    (void)direction;
    (void)projectiles;
    this->dispersion = 0;
}

AK47::~AK47() {}
