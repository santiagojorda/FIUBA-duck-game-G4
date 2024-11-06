#ifndef COWBOY_GUN
#define COWBOY_GUN

#include "gun.h"

#define MAX_AMMO 6

class CowboyGun : public Gun {
public:
    CowboyGun();
    void shoot(Player player) override;
};

#endif
