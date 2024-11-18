#ifndef GRANADE_H
#define GRANADE_H

#include "gun.h"
#include "projectile.h"

class Granade: public Gun {
public:
    Granade(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
