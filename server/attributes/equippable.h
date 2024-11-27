#ifndef EQUIPPABLE
#define EQUIPPABLE

#include <cstdint>
#include <memory>
#include "positionable.h"
#include "../../common/coordinate.h"

class Inventory;

class Equippable: public Positionable {
public:
    Equippable(){}
    explicit Equippable(const uint8_t& _texture_id, const Coordinate& _coordinate) : Positionable(_texture_id, _coordinate) {}
    virtual void equip(Inventory& inventory) = 0;
    virtual ~Equippable() {}
};

#endif
