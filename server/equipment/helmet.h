#ifndef HELMET
#define HELMET

#include "../attributes/equippable.h"

class Helmet: public Equippable {
public:
    Helmet();
    void equip(Inventory* inventory) override;

};

#endif
