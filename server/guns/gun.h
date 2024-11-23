#ifndef GUN
#define GUN

#include <cstdint>

#include "../../common/direction.h"
#include "../../common/weapons_id.h"
#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
#include "../player/inventory.h"

#include "list_projectiles.h"
#include "projectile_range.h"
#include "shooring_recoil.h"

class Gun: public Positionable, public Equippable {
protected:
    // cppcheck-suppress unusedStructMember
    uint8_t max_ammo;
    // cppcheck-suppress unusedStructMember
    uint8_t ammo;
    ShootingRecoil recoil;
    ProjectileRange projectile_range;

public:
    explicit Gun(const WeaponTextureID& _texture_id, const uint8_t& _max_ammo,
                 const ShootingRecoil& _recoil, const ProjectileRange& _projectile_range,
                 const Coordinate& _coordinate);


    // Comportamiento cuando se preciona el gatillo
    virtual void trigger(ListProjectiles& projectiles, Direction direction) = 0;

    // Comportamiento cuando se suelta el gatillo
    virtual void trigger_out(ListProjectiles& projectiles, Direction direction) = 0;

    void equip(Inventory* inventory) override;

    void translate() override;

    void translate_x(int pasos) override;

    void translate_y(int pasos) override;

    uint8_t get_ammo();

    uint8_t get_max_ammo();

    ShootingRecoil get_recoil();
    virtual ~Gun();
};


#endif
