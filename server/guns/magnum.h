#ifndef MAGNUM
#define MAGNUM

#include "gun.h"

#define MAX_AMMO 6

class Magnum: public Gun {
public:
    Magnum();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
