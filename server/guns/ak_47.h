#ifndef AK_47
#define AK_47

#include "gun.h"


class AK47: public Gun {
public:
    explicit AK47(const Coordinate& _coordinate);
    ListProjectiles shoot(Coordinate& shooter_position) override;
};

#endif
