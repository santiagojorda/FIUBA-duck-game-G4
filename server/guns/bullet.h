#ifndef BULLET
#define BULLET

#include "projectile.h"

#define MAX_RANGE_TILES 1 // medio

class Bullet : public Projectile {
public:
    explicit Bullet(uint8_t _range_tiles);
};

#endif
