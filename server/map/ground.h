#ifndef GROUND
#define GROUND

#include <cstdint>

#include "../attributes/positionable.h"

class Ground: public Positionable {
private:
public:
    explicit Ground(const Coordinate& _coordinate, const uint8_t& _texture_id);
    void translate() override {}
    void translate_x(int pasos) override { (void)pasos; }
    void translate_y(int pasos) override { (void)pasos; }
    ~Ground() {}
};

#endif