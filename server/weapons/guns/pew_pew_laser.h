#ifndef PEW_PEW_LASER_H
#define PEW_PEW_LASER_H

#include "../gun.h"


class PewPewLaser: public Gun {
private:
    bool blocked;

public:
    PewPewLaser(Coordinate _coordinate);


    // Dispara aumentado dispersion
    virtual void trigger(ListProjectiles& projectiles) override;

    // reinicia dispersion
    virtual void trigger_out(ListProjectiles& projectiles) override;

    ~PewPewLaser();
};

#endif
