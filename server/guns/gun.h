#ifndef GUN
#define GUN  

#include "../attributes/positionable.h"
#include "../attributes/statable.h"
#include "../attributes/equippable.h"
#include "../player/inventory.h"
#include "../../common/coordinate.h"
#include "list_projectiles.h"

class Gun : public Positionable, public Equippable {
private:
    uint8_t ammo; 

public:
    explicit Gun(uint8_t _ammo);
    virtual ListProjectiles shoot(Coordinate& shooter_position) = 0;
    void equip(Inventory* inventory) override;
};

#endif
