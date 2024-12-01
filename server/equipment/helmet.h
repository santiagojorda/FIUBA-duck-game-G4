#ifndef HELMET
#define HELMET

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"

class Helmet: public Equippable {
public:
    Helmet();
    void handle_equip(Inventory& inventory) override;
    std::shared_ptr<Equippable> clone() const override;

};

#endif
