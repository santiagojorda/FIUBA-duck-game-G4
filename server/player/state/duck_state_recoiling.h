#ifndef DUCK_STATE_RECOILING_H
#define DUCK_STATE_RECOILING_H

#include "duck_state.h"

class DuckStateRecoiling: public DuckState {
public:
    DuckStateRecoiling(const uint8_t& _player_id);
    ~DuckStateRecoiling();
};

#endif
