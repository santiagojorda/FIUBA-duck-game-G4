#ifndef SNIPER_H
#define SNIPER_H

#include "../gun.h"

class Sniper: public Gun {
private:
    bool blocked;

public:
    Sniper(const Coordinate& _coordinate);


    // Dispara aumentado dispersion
    virtual void trigger(ListProjectiles& projectiles, Direction direction) override;

    // reinicia dispersion
    virtual void trigger_out(ListProjectiles& projectiles, Direction direction) override;


    ~Sniper();
};

#endif
