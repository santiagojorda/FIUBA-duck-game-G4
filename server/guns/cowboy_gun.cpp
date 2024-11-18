#include "cowboy_gun.h"

#include "../../common/weapons_id.h"

struct CowboyConfig {
    uint8_t id = TEXTURE_WEAPONS::PISTOLA_COWBOY_ID;
    uint8_t max_ammo = 6;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::LARGE;
    uint8_t count_projectiles_x_shoot = 1;
};
CowboyConfig cowboy_config;

CowboyGun::CowboyGun(const Coordinate& _coordinate):
        Gun(cowboy_config.id,
            cowboy_config.max_ammo,
            cowboy_config.recoil,
            cowboy_config.range,
            _coordinate) 
    {}

ListProjectiles CowboyGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}