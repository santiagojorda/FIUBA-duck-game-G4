#ifndef STATABLE
#define STATABLE

#include <cstdint>

#include "../../common/rectangle.h"

class Statable {

private:
    uint8_t state = 0;
    uint8_t iter_frame = 0;

public:
    Statable();
    uint8_t get_state();
    uint8_t get_frame();
    ~Statable();
};

#endif
