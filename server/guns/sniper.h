#ifndef SNIPER_H
#define SNIPER_H

#include "gun.h"

class Sniper: public Gun {
public:
    Sniper(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
    void shoot(ListProjectiles& projectiles, Direction direction) override;
};

#endif
