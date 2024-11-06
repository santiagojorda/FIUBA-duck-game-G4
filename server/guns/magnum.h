#ifndef MAGNUM
#define MAGNUM

#include "gun.h"

#define MAX_AMMO 6

class Magnum : public Gun {
public:
    Magnum();
    void shoot(Player player) override;
};

#endif
