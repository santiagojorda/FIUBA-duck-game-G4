#ifndef COWBOY_GUN_H
#define COWBOY_GUN_H

#include "gun.h"

class CowboyGun: public Gun {
public:
    CowboyGun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
