#ifndef SERVER_POSITIONABLE_H_
#define SERVER_POSITIONABLE_H_

#include <cstdint>

#include "../common/coordinate.h"

class Positionable {

protected:
    Coordinate coordinates;

public:
    Positionable();

    virtual Coordinate get_coordinate() const;

    virtual void translate() = 0;
    virtual void translate_x() = 0;
    virtual void translate_y() = 0;

    virtual ~Positionable();
};

#endif  // SERVER_POSITIONABLE_H_
