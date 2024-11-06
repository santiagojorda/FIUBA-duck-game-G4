#ifndef GRANADE
#define GRANADE

#include "gun.h"

#define MAX_AMMO 1

class Granade : public Gun {
public:
    Granade();
    void shoot(Player player) override;
};

#endif
