#ifndef COWBOY_GUN
#define COWBOY_GUN

#include "gun.h"

class CowboyGun: public Gun {
public:
    CowboyGun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
