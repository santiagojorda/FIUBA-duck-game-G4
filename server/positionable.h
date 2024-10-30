#ifndef SERVER_POSITIONABLE_H_
#define SERVER_POSITIONABLE_H_

#include <cstdint>

#include "../common/rectangle.h"

class Positionable {

protected:
    Rectangle space;

public:
    Positionable();

    virtual Coordinate get_coordinate() const;

    virtual Rectangle get_rectangle() const;

    virtual void translate() = 0;
    virtual void translate_x(int pasos) = 0;
    virtual void translate_y(int pasos) = 0;

    virtual ~Positionable();
};

#endif  // SERVER_POSITIONABLE_H_
