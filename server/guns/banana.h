#ifndef BANANA
#define BANANA

#include "gun.h"

#define MAX_AMMO 1

class Banana : public Gun {
public:
    Banana();
    void shoot(Player player) override;
};

#endif
