#ifndef BANANA
#define BANANA

#include "gun.h"
#include "projectile.h"

#define MAX_AMMO 1
#define MAX_RANGE_TILES 5 // dice alcance medio

class Banana : public Gun, public Projectile {
public:
    Banana();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
