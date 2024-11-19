#ifndef DUCK_STATE_RUNNING_H
#define DUCK_STATE_RUNNING_H

#include "duck_state.h"

class DuckStateRunning: public DuckState{
public:
    DuckStateRunning();

    void update(Player& player) override;

    ~DuckStateRunning();
};

#endif
