#ifndef DUELING_GUN_H
#define DUELING_GUN_H

#include "../gun.h"


class DuelingGun: public Gun {
public:
    DuelingGun(const Coordinate& _coordinate);

    // Dispara con muhca dispersion
    virtual void trigger(ListProjectiles& projectiles) override;

    ~DuelingGun();
};


#endif  // DUELING_GUN_H
