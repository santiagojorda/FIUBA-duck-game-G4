#ifndef DUCK_STATE_JUMPING_H
#define DUCK_STATE_JUMPING_H

#include "duck_state.h"

class DuckStateJumping: public DuckState{
public:
    DuckStateJumping(Player& _player);

    void update(Player& player) override;

    ~DuckStateJumping();
};

#endif
