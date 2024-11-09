#ifndef PROJECTILE
#define PROJECTILE

#include "gun.h"
#include "../attributes/positionable.h"
#include "../attributes/statable.h"

class Projectile : public Positionable, public Statable {
private:
    // cppcheck-suppress unusedStructMember
    uint8_t range_tiles;
public:
    Projectile(uint8_t _range_tiles); 
    explicit Projectile(uint8_t _range_tiles, Coordinate _coordinate); 
};

#endif
