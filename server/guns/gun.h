#ifndef GUN
#define GUN

#include <cstdint>

#include "../../common/coordinate.h"
#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
// #include "../attributes/statable.h"
#include "../player/inventory.h"
#include "../../common/weapons_id.h"

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

    // virtual ListProjectiles generate_list_projectiles(Coordinate& shooter_position);
public:
    explicit Gun(const TextureID& _texture_id, const uint8_t& _max_ammo, const ShootingRecoil& _recoil, const ProjectileRange& _projectile_range,
                const Coordinate& _coordinate);

    virtual ListProjectiles shoot(Coordinate& shooter_position) = 0;
    ListProjectiles shoot(Coordinate& shooter_position, ShootingRecoil& _recoil);
    void equip(Inventory* inventory) override;
    void translate() override;
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;
    uint8_t get_ammo();
    uint8_t get_max_ammo();
};


#endif
