#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../attributes/positionable.h"
// #include "../attributes/statable.h"
#include "projectile_range.h"

class Projectile: public Positionable {  // es un statable
protected:
    ProjectileRange range_tiles;

public:
    explicit Projectile(const uint8_t& texture_id, ProjectileRange _range_tiles,
                        Coordinate _coordinate);
};

#endif
