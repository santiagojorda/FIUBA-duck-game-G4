#ifndef DUELING_GUN
#define DUELING_GUN

#include "gun.h"

#define MAX_AMMO 1

class DuelingGun : public Gun {
public:
    DuelingGun();
    void shoot(Player player) override;
};

#endif
