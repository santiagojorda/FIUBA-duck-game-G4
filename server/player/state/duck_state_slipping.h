#ifndef DUCK_STATE_SLIPPING_H
#define DUCK_STATE_SLIPPING_H

#include "duck_state.h"

class DuckStateSlipping: public DuckState{
public:
    DuckStateSlipping();

    void update(Player& player) override;
    ~DuckStateSlipping();
};

#endif
