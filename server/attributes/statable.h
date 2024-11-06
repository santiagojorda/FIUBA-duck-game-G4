#ifndef STATABLE
#define STATABLE

#include <cstdint>

#include "../../common/rectangle.h"

class Statable {

protected:
    uint8_t state;
    uint8_t iter_state;
    
public:
    Statable();
    ~Statable();
};

#endif
 