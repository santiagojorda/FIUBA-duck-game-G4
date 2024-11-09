#ifndef LASER_RIFLE
#define LASER_RIFLE

#include "gun.h"

#define MAX_AMMO 10

class LaserRifle : public Gun {
public:
    LaserRifle();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};
#endif
