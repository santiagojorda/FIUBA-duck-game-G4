#ifndef MAGNUM
#define MAGNUM

#include "gun.h"

class Magnum: public Gun {
public:
    Magnum(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
