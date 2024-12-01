#ifndef ARMOR
#define ARMOR

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"

class Armor: public Equippable {
public:
    Armor();
    void handle_equip(Inventory& inventory) override;
    std::shared_ptr<Equippable> clone() const override;
};

#endif