#ifndef LASER_RIFLE_H
#define LASER_RIFLE_H

#include "gun.h"

class LaserRifle: public Gun {
public:
    LaserRifle(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
    void shoot(ListProjectiles& projectiles, Direction direction) override;
};
#endif
