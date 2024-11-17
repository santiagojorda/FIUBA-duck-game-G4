#ifndef MAGNUM
#define MAGNUM

#include "gun.h"

#define MAX_AMMO 6

class Magnum: public Gun {
public:
    Magnum(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
