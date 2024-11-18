#ifndef SERVER_POSITIONABLE_H_
#define SERVER_POSITIONABLE_H_

#include <cstdint>

#include "../../common/rectangle.h"

class Positionable {

private:
    uint8_t id = 0;
    uint8_t texture_id;

protected:
    Rectangle space;

    void set_texture_id(const uint8_t& _texture_id);

public:
    Positionable();
    Positionable(const uint8_t& _texture_id, const Coordinate& _coordinate);

    Coordinate get_coordinate() const;

    Rectangle get_rectangle() const;

    virtual void translate() = 0;
    virtual void translate_x(int pasos) = 0;
    virtual void translate_y(int pasos) = 0;
    uint8_t get_id();
    uint8_t get_texture_id();
    virtual ~Positionable();
};

#endif  // SERVER_POSITIONABLE_H_
