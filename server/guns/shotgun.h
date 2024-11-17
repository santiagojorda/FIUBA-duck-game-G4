#ifndef SHOTGUN
#define SHOTGUN

#include "gun.h"

#define MAX_AMMO 2

class Shotgun: public Gun {
public:
    Shotgun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
