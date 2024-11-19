#ifndef DUCK_STATE_DEAD_H
#define DUCK_STATE_DEAD_H

#include "duck_state.h"

class DuckStateDead: public DuckState{
public:
    DuckStateDead();

    void update(Player& player) override;

    ~DuckStateDead();
};

#endif