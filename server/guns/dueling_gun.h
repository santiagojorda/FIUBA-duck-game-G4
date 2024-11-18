#ifndef DUELING_GUN
#define DUELING_GUN

#include "gun.h"

class DuelingGun: public Gun {
public:
    DuelingGun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
