#ifndef STATABLE
#define STATABLE

#include <cstdint>

#include "../../common/rectangle.h"

class Statable {

protected:
    uint8_t state;
    uint8_t frame = 0;  // imagen -> depende de las iteracioens
    uint8_t tick = 0;   // iteraciones
    uint8_t get_tick();
    void reset();
    void set_state(const uint8_t& new_state);
    virtual void update() = 0;

public:
    Statable(const uint8_t& _initial_state);
    uint8_t get_frame();
    uint8_t get_state();
    virtual ~Statable();
};

#endif
