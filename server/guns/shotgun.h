#ifndef SHOTGUN
#define SHOTGUN

#include "gun.h"

class Shotgun: public Gun {
public:
    Shotgun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
