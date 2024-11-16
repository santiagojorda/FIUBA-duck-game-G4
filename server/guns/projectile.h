#ifndef PROJECTILE
#define PROJECTILE

#include "../attributes/positionable.h"
// #include "../attributes/statable.h"
#include "projectile_range.h"

class Projectile: public Positionable {  // es un statable
protected:
    ProjectileRange range_tiles;

public:
    Projectile();
    explicit Projectile(ProjectileRange _range_tiles);
    explicit Projectile(ProjectileRange _range_tiles, Coordinate _coordinate);
    void set_projectile_range(ProjectileRange _range_tiles);
};

#endif
