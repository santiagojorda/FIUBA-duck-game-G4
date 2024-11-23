#ifndef MAGNUM_H
#define MAGNUM_H

#include "../gun.h"


class Magnum: public Gun {
private:
    bool blocked;

public:
    Magnum(const Coordinate& _coordinate);

    //Dispara aumentado dispersion 
    virtual void trigger(ListProjectiles& projectiles, Direction direction) override; 

    //reinicia dispersion 
    virtual void trigger_out(ListProjectiles& projectiles, Direction direction) override;


    ~Magnum();
};

#endif
