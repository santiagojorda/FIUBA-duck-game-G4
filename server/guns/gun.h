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

public:
    explicit Gun(uint8_t _ammo, ShootingRecoil _recoil, ProjectileRange _projectile_range);
    virtual ListProjectiles shoot(Coordinate& shooter_position) = 0;
    ListProjectiles shoot(Coordinate& shooter_position, ShootingRecoil& _recoil);
    void equip(Inventory* inventory) override;
    uint8_t get_ammo();
};

#endif
