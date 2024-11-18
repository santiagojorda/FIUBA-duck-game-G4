#include "dueling_gun.h"

#include "../../common/weapons_id.h"

struct DuelingConfig {
    uint8_t id = TEXTURE_WEAPONS::PISTOLA_DUELOS_ID;
    uint8_t max_ammo = 1;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::VERY_SHORT;
    uint8_t count_projectiles_x_shoot = 1;
};
DuelingConfig dueling_config;

DuelingGun::DuelingGun(const Coordinate& _coordinate):
        Gun(dueling_config.id,
            dueling_config.max_ammo,
            dueling_config.recoil,
            dueling_config.range,
            _coordinate) 
    {}

ListProjectiles DuelingGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}
