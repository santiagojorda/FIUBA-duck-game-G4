#ifndef GUN
#define GUN

#include <cstdint>

#include "../attributes/directionable.h"
#include "../../common/weapons_id.h"
#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
#include "../player/inventory.h"

#include "list_projectiles.h"
#include "projectile_range.h"
#include "shooring_recoil.h"

#define INITIAL_DISPERSION 0

class Gun: public Positionable, public Equippable, public Directionable {
protected:
    // cppcheck-suppress unusedStructMember
    uint8_t max_ammo;
    // cppcheck-suppress unusedStructMember
    uint8_t ammo;
    // cppcheck-suppress unusedStructMember
    int dispersion;
    ShootingRecoil recoil;
    ProjectileRange projectile_range;

public:
    explicit Gun(const WeaponTextureID& _texture_id, const uint8_t& _max_ammo,
                 const ShootingRecoil& _recoil, const ProjectileRange& _projectile_range,
                 const Coordinate& _coordinate);


    // Comportamiento cuando se preciona el gatillo
    virtual void trigger(ListProjectiles& projectiles);

    // Comportamiento cuando se suelta el gatillo
    virtual void trigger_out(ListProjectiles& projectiles);

    void equip(Inventory* inventory) override;

    uint8_t get_ammo();

    uint8_t get_max_ammo();

    ShootingRecoil get_recoil();
    virtual ~Gun();
};


#endif
