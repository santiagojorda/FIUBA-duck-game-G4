#ifndef GUN
#define GUN

#include <cstdint>

#include "../../common/coordinate.h"
#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
// #include "../attributes/statable.h"
#include "../player/inventory.h"

#include "list_projectiles.h"
#include "projectile_range.h"
#include "shooring_recoil.h"

class Gun: public Positionable, public Equippable {
protected:
    // cppcheck-suppress unusedStructMember
    uint8_t ammo;
    ShootingRecoil recoil;
    ProjectileRange projectile_range;

    ListProjectiles generate_list_projectiles();
public:
    explicit Gun(uint8_t _ammo, ShootingRecoil _recoil, ProjectileRange _projectile_range);
    explicit Gun(uint8_t& _texture_id, uint8_t& _ammo, ShootingRecoil& _recoil, ProjectileRange&& _projectile_range,
                 Coordinate& _coordinate);

    virtual ListProjectiles shoot(Coordinate& shooter_position) = 0;
    ListProjectiles shoot(Coordinate& shooter_position, ShootingRecoil& _recoil);
    void equip(Inventory* inventory) override;
    void translate() override;
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;
    uint8_t get_ammo();
};

#endif
