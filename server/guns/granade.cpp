#include "granade.h"

#include "../../common/weapons_id.h"

#define MAX_RANGE_TILES 1

struct GranadeConfig {
    WeaponTextureID id = WeaponTextureID::GRANATE;
    uint8_t max_ammo = 1;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::MEDIUM;
    uint8_t count_projectiles_x_shoot = 1;
};
GranadeConfig granade_config;

Granade::Granade(const Coordinate& _coordinate): 
        Gun(granade_config.id,
            granade_config.max_ammo,
            granade_config.recoil,
            granade_config.range,
            _coordinate) 
    {}


ListProjectiles Granade::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}