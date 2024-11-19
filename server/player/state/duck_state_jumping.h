#ifndef DUCK_STATE_JUMPING_H
#define DUCK_STATE_JUMPING_H

#include "duck_state.h"

class DuckStateJumping: public DuckState{
public:
    DuckStateJumping();

    void update(Player& player) override;

    ~DuckStateJumping();
};

#endif
