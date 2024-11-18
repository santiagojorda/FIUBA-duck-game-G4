#include "shotgun.h"

#include "../../common/weapons_id.h"

struct ShotgunConfig {
    TextureID id = TextureID::SHOTGUN;
    uint8_t max_ammo = 2;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::LARGE;
    uint8_t count_projectiles_x_shoot = 1;
};
ShotgunConfig shotgun_config;

Shotgun::Shotgun(const Coordinate& _coordinate): 
        Gun(shotgun_config.id,
            shotgun_config.max_ammo,
            shotgun_config.recoil,
            shotgun_config.range,
            _coordinate) 
    {}


ListProjectiles Shotgun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}