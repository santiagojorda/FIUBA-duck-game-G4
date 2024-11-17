#ifndef PEW_PEW_LASER
#define PEW_PEW_LASER

#include "gun.h"

#define MAX_AMMO 12

class PewPewLaser: public Gun {
public:
    PewPewLaser(Coordinate _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
