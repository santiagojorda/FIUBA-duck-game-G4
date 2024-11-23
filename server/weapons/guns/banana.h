#ifndef BANANA_H
#define BANANA_H

#include "../gun.h"


class Banana: public Gun {
public:
    Banana(const Coordinate& _coordinate);


    // vemos
    // virtual void trigger(ListProjectiles& projectiles) override;

    // vemos
    // virtual void trigger_out(ListProjectiles& projectiles) override;

    ~Banana();
};

#endif
