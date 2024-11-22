#include "magnum.h"

#include "../../common/weapons_id.h"

#include "bullet.h"
#define MAX_AMMO 6

struct MagnumConfig {
    WeaponTextureID id = WeaponTextureID::MAGNUM;
    uint8_t max_ammo = 6;
    ShootingRecoil recoil = ShootingRecoil::SHORT;
    ProjectileRange range = ProjectileRange::VERY_LARGE;
    uint8_t count_projectiles_x_shoot = 1;
};
MagnumConfig magnum_config;

Magnum::Magnum(const Coordinate& _coordinate):
        Gun(magnum_config.id, magnum_config.max_ammo, magnum_config.recoil, magnum_config.range,
            _coordinate) {}

ListProjectiles Magnum::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}

void Magnum::shoot(ListProjectiles& projectiles, Direction direction) {
    (void)direction;
    (void)projectiles;
    // for (int i = 0; i < magnum_config.count_projectiles_x_shoot; i++) {
    //     if (this->ammo > 0) {
    //         projectiles.add(new Bullet(this->projectile_range, this->get_coordinate()));
    //         this->ammo--;
    //     }
    // }
}
