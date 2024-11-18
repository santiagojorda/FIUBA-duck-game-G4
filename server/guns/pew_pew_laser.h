#ifndef PEW_PEW_LASER
#define PEW_PEW_LASER

#include "gun.h"

class PewPewLaser: public Gun {
public:
    PewPewLaser(Coordinate _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
