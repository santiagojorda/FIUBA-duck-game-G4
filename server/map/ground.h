#ifndef GROUND
#define GROUND

#include <cstdint>

#include "../attributes/positionable.h"

class Ground: public Positionable {
private:
    uint8_t state;
public:
    explicit Ground(const Coordinate& _coordinate, const uint8_t& _texture_id) : Positionable(_texture_id, _coordinate){}
    void translate() override {}
    void translate_x(int pasos) override { (void)pasos; }
    void translate_y(int pasos) override { (void)pasos; }
    ~Ground() {}
};

#endif