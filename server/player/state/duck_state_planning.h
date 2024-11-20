#ifndef DUCK_STATE_PLANNING_H
#define DUCK_STATE_PLANNING_H

#include "duck_state.h"

class DuckStatePlanning: public DuckState{
public:
    DuckStatePlanning(const uint8_t& _player_id);
    ~DuckStatePlanning();
};

#endif
