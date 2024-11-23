#ifndef LASER_RIFLE_H
#define LASER_RIFLE_H

#include "../gun.h"


class LaserRifle: public Gun {
public:
    LaserRifle(const Coordinate& _coordinate);

    // Dispara aumentado dispersion
    void trigger(ListProjectiles& projectiles, Direction direction) override;

    // nada
    void trigger_out(ListProjectiles& projectiles, Direction direction) override;

    ~LaserRifle();
};
#endif
