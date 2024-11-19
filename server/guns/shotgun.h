#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "gun.h"

class Shotgun: public Gun {
private:
    bool reloaded;

public:
    Shotgun(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
    void shoot(ListProjectiles& projectiles, Direction direction) override;

};

#endif
