#ifndef HELMET
#define HELMET

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"

class Helmet: public Positionable, public Equippable {
public:
    Helmet();
    void equip(Inventory* inventory) override;
};

#endif
