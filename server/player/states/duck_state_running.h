#ifndef DUCK_STATE_RUNNING_H
#define DUCK_STATE_RUNNING_H


#include "../../../common/direction.h"
#include "../duck_state.h"

#define RUN_STEP 5
#define TICKS_PER_FRAME 1

class DuckStateRunning: public DuckState {
private:
public:
    explicit DuckStateRunning(const uint8_t& _player_id);

    void update_state(Positionable& positionable, GameLogic& game_logic) override;
    void execute(Positionable& positionable, GameLogic& game_logic) override;
    void move(Positionable& positionable);

    ~DuckStateRunning();
};

#endif
