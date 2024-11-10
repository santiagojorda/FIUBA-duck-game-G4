#ifndef SHOTGUN
#define SHOTGUN

#include "gun.h"

#define MAX_AMMO 2

class Shotgun: public Gun {
public:
    Shotgun();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
