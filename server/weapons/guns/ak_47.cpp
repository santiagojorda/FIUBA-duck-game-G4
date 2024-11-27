#include "ak_47.h"

#include "../projectiles/bullet.h"

gun_config ak_config = {WeaponTextureID::AK_47,  30, ShootingRecoil::SHORT,
                        ProjectileRange::MEDIUM, 1,  5};

AK47::AK47(const Coordinate& _coordinate): Gun(ak_config, _coordinate) {}

void AK47::trigger(ListProjectiles& projectiles) {
    this->dispersion++;

    // esto hay que refactorizar
    Rectangle cañonaso = this->space;
    int x;
    if (get_direction() == Direction::RIGHT) {
        x = cañonaso.get_x_max();
    } else {
        x = cañonaso.get_x_min();
    }

    // refactorizar
    Coordinate bullet_postion(x, ((cañonaso.get_y_min() + cañonaso.get_y_max()) / 2) - 5, 0, 0);

    for (int i = 0; i < ak_config.count_projectiles_x_shoot; i++) {
        if (this->ammo > 0 && this->delay_counter()) {
            projectiles.add(std::make_shared<Bullet>(this->projectile_range, bullet_postion,
                                                     this->get_direction(), this->dispersion));
            this->ammo--;
        }
    }
}

void AK47::trigger_out(ListProjectiles& projectiles) {
    this->dispersion = 0;
    Gun::trigger_out(projectiles);
}

AK47::~AK47() {}
