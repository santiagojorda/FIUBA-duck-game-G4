#include "dueling_gun.h"

#include "../../common/weapons_id.h"
#include <functional>
#include "bullet.h"

struct DuelingConfig {
    WeaponTextureID id = WeaponTextureID::DUELING_GUN;
    uint8_t max_ammo = 1;
    ShootingRecoil recoil = ShootingRecoil::NONE;
    ProjectileRange range = ProjectileRange::VERY_SHORT;
    uint8_t count_projectiles_x_shoot = 1;
};
DuelingConfig dueling_config;

DuelingGun::DuelingGun(const Coordinate& _coordinate):
        Gun(dueling_config.id, dueling_config.max_ammo, dueling_config.recoil, dueling_config.range,
            _coordinate) {}

ListProjectiles DuelingGun::shoot(Coordinate& shooter_position) {
    (void)shooter_position;
    return ListProjectiles();
}

void  DuelingGun::shoot(ListProjectiles& projectiles, Direction direction)  { 
    (void)direction;
    for (int i = 0; i < dueling_config.count_projectiles_x_shoot; i++){
        if(this->ammo > 0){
            projectiles.add(new Bullet(this->projectile_range ,this->get_coordinate()));
            this->ammo--;
        }
    }
}
