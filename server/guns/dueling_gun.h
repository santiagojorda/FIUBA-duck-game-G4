#ifndef DUELING_GUN
#define DUELING_GUN

#include "gun.h"

#define MAX_AMMO 1

class DuelingGun: public Gun {
public:
    DuelingGun();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
