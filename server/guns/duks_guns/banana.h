#ifndef BANANA_H
#define BANANA_H

#include "../gun.h"


class Banana: public Gun {
public:
    Banana(const Coordinate& _coordinate);


    // vemos
    virtual void trigger(ListProjectiles& projectiles, Direction direction) override;

    // vemos
    virtual void trigger_out(ListProjectiles& projectiles, Direction direction) override;

    ~Banana();
};

#endif
