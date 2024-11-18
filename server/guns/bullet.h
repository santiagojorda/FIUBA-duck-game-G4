#ifndef BULLET
#define BULLET

#include "projectile.h"

#define MAX_RANGE_TILES 1  // medio

class Bullet: public Projectile {
public:
    explicit Bullet(const ProjectileRange& _range_tiles, const Coordinate& _coordinate);
};

#endif
