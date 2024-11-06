#ifndef AK_47
#define AK_47

#include "gun.h"

#define MAX_AMMO 30

class AK47 : public Gun {
public:
    AK47();
    void shoot(Player player) override;
};

#endif
