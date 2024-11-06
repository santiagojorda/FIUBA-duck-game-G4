#ifndef LASER_RIFLE
#define LASER_RIFLE

#include "gun.h"

#define MAX_AMMO 10

class LaserRifle : public Gun {
public:
    LaserRifle();
    void shoot(Player player) override;
};

#endif
