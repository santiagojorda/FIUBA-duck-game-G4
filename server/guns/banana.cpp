#include "banana.h"

#include "../../common/weapons_id.h"

#include <functional>

struct BananaConfig {
    WeaponTextureID id = WeaponTextureID::BANANA;
    uint8_t max_ammo = 1;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::MEDIUM;
    uint8_t count_projectiles_x_shoot = 1;
};
BananaConfig banana_config;

Banana::Banana(const Coordinate& _coordinate):
        Gun(banana_config.id, banana_config.max_ammo, banana_config.recoil, banana_config.range,
            _coordinate) {}

ListProjectiles Banana::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}

void  Banana::shoot(ListProjectiles& projectiles, Direction direction)  { 
    (void)direction;
    (void) projectiles;
}
