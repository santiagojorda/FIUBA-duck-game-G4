#include "ak_47.h"

#include "../../common/weapons_id.h"

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

// ListProjectiles AK47::generate_list_projectiles(Coordinate& shooter_position){
//     (void)shooter_position;
//     ListProjectiles projectiles;
//     return projectiles;
// }


ListProjectiles AK47::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}