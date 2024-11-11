#ifndef STATABLE
#define STATABLE

#include <cstdint>

#include "../../common/rectangle.h"

class Statable {

private:
    uint8_t state = 0;
    uint8_t frame = 0;
    void set_state(uint8_t new_state);
    void set_frame(uint8_t new_frame);

public:
    Statable();
    uint8_t get_state();
    uint8_t get_frame();
    ~Statable();
};

#endif
