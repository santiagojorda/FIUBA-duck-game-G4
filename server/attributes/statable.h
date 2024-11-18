#ifndef STATABLE
#define STATABLE

#include <cstdint>

#include "../../common/rectangle.h"
#include "../../common/state_duck.h"

class Statable {

protected:
    DuckState state;
    uint8_t frame = 0;
    void set_state(DuckState new_state);

public:
    Statable(DuckState);
    DuckState get_state();
    uint8_t get_frame();
    void reset();
    virtual void update() = 0;
    virtual ~Statable();
};

#endif
