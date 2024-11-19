#ifndef DUCK_STATE_IDLE_H
#define DUCK_STATE_IDLE_H

#include "duck_state.h"

class DuckStateIdle: public DuckState{
public:
    DuckStateIdle();
    void update(Player& player) override;
    ~DuckStateIdle();
};

#endif
