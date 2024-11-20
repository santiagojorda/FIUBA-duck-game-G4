#ifndef DUCK_STATE_SLIPPING_H
#define DUCK_STATE_SLIPPING_H

#include "duck_state.h"

class DuckStateSlipping: public DuckState{
public:
    DuckStateSlipping(const uint8_t& _player_id);

    ~DuckStateSlipping();
};

#endif
