#ifndef GRANADE
#define GRANADE

#include "gun.h"
#include "projectile.h"

#define MAX_AMMO 1
#define MAX_RANGE_TILES 1

class Granade : public Gun, public Projectile {
public:
    Granade();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
