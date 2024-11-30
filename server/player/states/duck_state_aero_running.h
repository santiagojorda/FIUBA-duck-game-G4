#ifndef DUCK_STATE_AERO_RUNNING_H
#define DUCK_STATE_AERO_RUNNING_H

#include "../duck_state.h"

#define RUN_STEP 5

class DuckStateAeroRunning: public DuckState {
public:
    DuckStateAeroRunning(const uint8_t& _player_id);
    void execute(Positionable& positionable, GameLogic& game_logic) override;
    void move(Positionable& positionable);
    ~DuckStateAeroRunning();
};

#endif
