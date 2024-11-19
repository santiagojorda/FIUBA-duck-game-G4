#ifndef DUCK_STATE_SLIPPING_H
#define DUCK_STATE_SLIPPING_H

#include "duck_state.h"

class DuckStateSlipping: public DuckState{
public:
    DuckStateSlipping(Player& _player);

    void update(Player& player) override;
    ~DuckStateSlipping();
};

#endif
