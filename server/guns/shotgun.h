#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "gun.h"

class Shotgun: public Gun {
public:
    Shotgun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
