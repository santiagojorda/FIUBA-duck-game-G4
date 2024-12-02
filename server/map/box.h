#ifndef BOX
#define BOX

#include <cstdint>
#include "../../common/boxes_id.h"

#include "../attributes/positionable.h"
    enum GroundState : uint8_t{
        CLOSE,
        OPEN
    };
class Box: public Positionable {
private:
    uint8_t state;

public:
    explicit Box(const Coordinate& _coordinate)
    : Positionable((uint8_t)BoxesTextureID::DEFAULT, _coordinate),
            state(GroundState::CLOSE)
        {}
    
    void translate() override {}
    void translate_x(int pasos) override { (void)pasos; }
    void translate_y(int pasos) override { (void)pasos; }    
    bool is_open() { return state == GroundState::OPEN; }
    void open() { state = GroundState::OPEN; }
    uint8_t get_state() { return state; }
    ~Box() {}
};

#endif