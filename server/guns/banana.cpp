#include "banana.h"

#include "../../common/weapons_id.h"


struct BananaConfig {
    uint8_t id = TEXTURE_WEAPONS::BANANA_ID;
    uint8_t max_ammo = 1;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::MEDIUM;
    uint8_t count_projectiles_x_shoot = 1;
};
BananaConfig banana_config;

Banana::Banana(const Coordinate& _coordinate):
        Gun(banana_config.id,
            banana_config.max_ammo,
            banana_config.recoil,
            banana_config.range,
            _coordinate) 
    {}

ListProjectiles Banana::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}