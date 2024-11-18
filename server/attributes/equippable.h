#ifndef EQUIPPABLE
#define EQUIPPABLE

#include <cstdint>

class Inventory;  // forward declaration -> para que no haya circularidad de inclusiones

class Equippable {
public:
    virtual void equip(Inventory* inventory) = 0;
    virtual ~Equippable() {}
};

#endif
