#ifndef COWBOY_GUN_H
#define COWBOY_GUN_H

#include "../gun.h"

class CowboyGun: public Gun {
private:
    bool blocked;

public:
    CowboyGun(const Coordinate& _coordinate);

    // Comportamiento cuando se preciona el gatillo
    virtual void trigger(ListProjectiles& projectiles) override;

    // Comportamiento cuando se suelta el gatillo
    virtual void trigger_out(ListProjectiles& projectiles) override;

    ~CowboyGun();
};

#endif
