#ifndef SNIPER
#define SNIPER

#include "gun.h"

class Sniper: public Gun {
public:
    Sniper(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
