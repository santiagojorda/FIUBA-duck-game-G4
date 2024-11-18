#include "sniper.h"

#include "../../common/weapons_id.h"

struct SniperConfig {
    WeaponTextureID id = WeaponTextureID::SNIPER;
    uint8_t max_ammo = 6;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::MAX;
    uint8_t count_projectiles_x_shoot = 1;
};
SniperConfig sniper_config;

Sniper::Sniper(const Coordinate& _coordinate): 
        Gun(sniper_config.id,
            sniper_config.max_ammo,
            sniper_config.recoil,
            sniper_config.range,
            _coordinate) 
    {}

ListProjectiles Sniper::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}