#ifndef DUCK_STATE_RUNNING_H
#define DUCK_STATE_RUNNING_H

#include "../../../common/direction.h"
#include "../duck_state.h"
class DuckStateRunning: public DuckState {
private:
    int count_steps_to_execute = 0;
    int count_steps_updated = 0;

public:
    DuckStateRunning(const uint8_t& _player_id);

    void update(Player& player, GamePhysics& physics) override;
    void execute(Player& player, GamePhysics& physics) override;
    void move(Player& player, Direction& direction);

    ~DuckStateRunning();
};

#endif
