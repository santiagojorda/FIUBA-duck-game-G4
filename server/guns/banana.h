#ifndef BANANA_H
#define BANANA_H

#include "gun.h"
#include "projectile.h"

class Banana: public Gun {
public:
    Banana(const Coordinate& _coordinate);

    ListProjectiles shoot(Coordinate& shooter_position) override;

    void shoot(ListProjectiles& projectiles, Direction direction) override;
};

#endif
