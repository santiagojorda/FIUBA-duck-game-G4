#ifndef GRANADE
#define GRANADE

#include "gun.h"
#include "projectile.h"

#define MAX_AMMO 1
#define MAX_RANGE_TILES 1

class Granade: public Gun {
public:
    Granade(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
