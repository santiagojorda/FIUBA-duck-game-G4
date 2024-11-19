#ifndef DUCK_STATE_PLANNING_H
#define DUCK_STATE_PLANNING_H

#include "duck_state.h"

class DuckStatePlanning: public DuckState{
public:
    DuckStatePlanning();
    void update(Player& player) override;
    ~DuckStatePlanning();
};

#endif
