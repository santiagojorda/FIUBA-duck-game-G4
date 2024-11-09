#ifndef ARMOR
#define ARMOR

#include "../attributes/positionable.h"
#include "../attributes/equippable.h"


class Armor : public Positionable, public Equippable{
public:
    Armor();
    void equip(Inventory* inventory) override;
};

#endif