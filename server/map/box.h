#ifndef BOX
#define BOX

#include <cstdint>

#include "../attributes/positionable.h"

class Box: public Positionable {
private:
public:
    explicit Box(const Coordinate& _coordinate, const uint8_t& _texture_id);
    void translate() override {}
    void translate_x(int pasos) override { (void)pasos; }
    void translate_y(int pasos) override { (void)pasos; }
    ~Box() {}
};

#endif