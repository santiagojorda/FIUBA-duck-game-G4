#ifndef GRANADE_H
#define GRANADE_H

#include "../gun.h"

class Granade: public Gun {
public:
    explicit Granade(const Coordinate& _coordinate);

    //
    // virtual void trigger(ListProjectiles& projectiles) override;

    //
    // virtual void trigger_out(ListProjectiles& projectiles) override;

    ~Granade();
};

#endif
