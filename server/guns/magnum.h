#ifndef MAGNUM_H
#define MAGNUM_H

#include "gun.h"

class Magnum: public Gun {
public:
    Magnum(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
    void shoot(ListProjectiles& projectiles, Direction direction) override;

};

#endif
