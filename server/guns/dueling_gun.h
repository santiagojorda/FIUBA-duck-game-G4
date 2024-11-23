#ifndef DUELING_GUN_H
#define DUELING_GUN_H

#include "gun.h"

class DuelingGun: public Gun {
public:
    DuelingGun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
    void shoot(ListProjectiles& projectiles, Direction direction) override;
};


#endif
