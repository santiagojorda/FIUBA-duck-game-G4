#ifndef BOX
#define BOX

#include <cstdint>
#include "../../common/boxes_id.h"

#include "../attributes/positionable.h"

class Box: public Positionable {
private:
public:
    explicit Box(const Coordinate& _coordinate): Positionable((uint8_t)BoxesTextureID::DEFAULT, _coordinate) {}
    Box(const Box& other) : Positionable(other.get_id(), other.get_coordinate()){}

    void translate() override {}
    void translate_x(int pasos) override { (void)pasos; }
    void translate_y(int pasos) override { (void)pasos; }
    ~Box() {}
};

#endif