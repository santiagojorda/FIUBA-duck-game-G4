#ifndef DUCK_STATE_DEAD_H
#define DUCK_STATE_DEAD_H

#include "duck_state.h"

class DuckStateDead: public DuckState {
public:
    DuckStateDead(const uint8_t& _player_id);

    ~DuckStateDead();
};

#endif
