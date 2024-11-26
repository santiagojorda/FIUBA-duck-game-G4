#ifndef EQUIPPABLE
#define EQUIPPABLE

#include <cstdint>
#include <memory>

class Inventory;

class Equippable {
public:
    virtual void equip(Inventory& inventory) = 0;
    virtual ~Equippable() {}
};

#endif
