#ifndef HELMET
#define HELMET

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"

class Helmet: public Equippable {
public:
    Helmet();
    void equip(Inventory& inventory) override;
};

#endif
