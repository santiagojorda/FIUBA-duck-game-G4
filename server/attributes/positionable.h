#ifndef SERVER_POSITIONABLE_H_
#define SERVER_POSITIONABLE_H_

#include <cstdint>

#include "../../common/rectangle.h"

class Positionable {

private:
    uint8_t texture_id;

protected:
    uint8_t id = 0;
    Rectangle space;

public:
    Positionable();
    Positionable(const uint8_t& _texture_id, const Coordinate& _coordinate);

    Coordinate get_coordinate() const;

    void set_coordinate(const Coordinate& new_coordinate);

    Rectangle get_rectangle() const;

    virtual void translate() = 0;
    virtual void translate_x(int pasos) = 0;
    virtual void translate_y(int pasos) = 0;
    uint8_t get_id();
    uint8_t get_texture_id();
    virtual ~Positionable();
};

#endif  // SERVER_POSITIONABLE_H_
