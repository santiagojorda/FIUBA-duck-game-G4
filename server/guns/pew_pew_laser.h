#ifndef PEW_PEW_LASER
#define PEW_PEW_LASER

#include "gun.h"

#define MAX_AMMO 12

class PewPewLaser : public Gun {
public:
    PewPewLaser();
    void shoot(Player player) override;
};

#endif
