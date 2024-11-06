#ifndef ARMOR
#define ARMOR

#include "../attributes/equippable.h"

class Armor : public Equippable{
public:
    Armor();
    void equip(Inventory* inventory) override;
};

#endif