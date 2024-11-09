#ifndef SNIPER
#define SNIPER

#include "gun.h"

#define MAX_AMMO 6

class Sniper : public Gun {
public:
    Sniper();
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
