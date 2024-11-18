#ifndef LASER_RIFLE
#define LASER_RIFLE

#include "gun.h"

class LaserRifle: public Gun {
public:
    LaserRifle(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};
#endif
