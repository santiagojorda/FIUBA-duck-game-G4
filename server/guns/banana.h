#ifndef BANANA
#define BANANA

#include "gun.h"
#include "projectile.h"

#define MAX_AMMO 1

class Banana: public Gun {
public:
    Banana(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
