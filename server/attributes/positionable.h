#ifndef SERVER_POSITIONABLE_H_
#define SERVER_POSITIONABLE_H_

#include <cstdint>

#include "../../common/rectangle.h"

class Positionable {

private:
    uint8_t id = 0;
    uint8_t texture_id = 0;

protected:
    Rectangle space;

public:
    Positionable();
    Positionable(Coordinate& _coordinate);

    virtual Coordinate get_coordinate() const;

    virtual Rectangle get_rectangle() const;

    virtual void translate() = 0;
    virtual void translate_x(int pasos) = 0;
    virtual void translate_y(int pasos) = 0;
    uint8_t get_id();
    uint8_t get_texture_id();
    virtual ~Positionable();
};

#endif  // SERVER_POSITIONABLE_H_
