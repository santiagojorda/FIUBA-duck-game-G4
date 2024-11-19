#ifndef DUCK_STATE_RECOILING_H
#define DUCK_STATE_RECOILING_H

#include "duck_state.h"

class DuckStateRecoiling: public DuckState{
public:
    DuckStateRecoiling();
    void update(Player& player) override;
    ~DuckStateRecoiling();
};

#endif
