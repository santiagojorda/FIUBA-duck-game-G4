#ifndef DUCK_STATE_CROUCHING_H
#define DUCK_STATE_CROUCHING_H

#include "duck_state.h"

class DuckStateCrouching: public DuckState{
public:
    DuckStateCrouching(Player& _player);
    void update(Player& player) override; 
    ~DuckStateCrouching();
};

#endif
