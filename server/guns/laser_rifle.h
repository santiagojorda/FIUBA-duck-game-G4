#ifndef LASER_RIFLE
#define LASER_RIFLE

#include "gun.h"

class LaserRifle : public Gun {
public:
    void shoot() override;
};

#endif
