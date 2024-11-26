#ifndef ARMOR
#define ARMOR

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"

class Armor: public Positionable, public Equippable {
public:
    Armor();
    void equip(Inventory& inventory) override;
};

#endif