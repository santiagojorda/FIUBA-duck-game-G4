#ifndef DUCK_STATE_FALLING_H
#define DUCK_STATE_FALLING_H

#include "duck_state.h"

class DuckStateFalling: public DuckState{
public:
    DuckStateFalling();

    void update(Player& player) override;
    ~DuckStateFalling();
};

#endif
