#ifndef GROUND
#define GROUND

#include "../attributes/positionable.h"

class Ground: public Positionable {
private:

public:
    explicit Ground(Coordinate _coordinate);
    void translate() override {}
    void translate_x(int pasos) override {(void)pasos;}
    void translate_y(int pasos) override {(void)pasos;}
    ~Ground() {}
};

#endif