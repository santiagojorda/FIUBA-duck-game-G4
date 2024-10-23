#ifndef POSITIONABLE_H
#define POSITIONABLE_H

#include <cstdint>
#include "../common/coordinate.h"

class Positionable{

private:
    Coordinate coordinates;

public:
    Positionable();
    virtual void translate() = 0;
    virtual void translate_x() = 0;
    virtual void translate_y() = 0;
};

#endif
