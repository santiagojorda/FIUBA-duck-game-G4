#ifndef SNIPER
#define SNIPER

#include "gun.h"

#define MAX_AMMO 6

class Sniper : public Gun {
public:
    Sniper();
    void shoot(Player player) override;
};

#endif
