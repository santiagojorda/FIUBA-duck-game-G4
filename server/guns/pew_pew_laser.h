#ifndef PEW_PEW_LASER_H
#define PEW_PEW_LASER_H

#include "gun.h"

class PewPewLaser: public Gun {
public:
    PewPewLaser(Coordinate _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
