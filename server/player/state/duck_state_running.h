#ifndef DUCK_STATE_RUNNING_H
#define DUCK_STATE_RUNNING_H

#include "duck_state.h"
#include "../../../common/direction.h"

class DuckStateRunning: public DuckState{
private:
    Direction& direction;
    int count_steps_to_execute = 0;
    int count_steps_updated = 0;
public:
    DuckStateRunning(const uint8_t& _player_id, Direction& _direction);

    void update(Player& player, GamePhysics& physics) override;
    void execute(Player& player, GamePhysics& physics) override;
    void move(Player& player, Direction& direction);

    ~DuckStateRunning();
};

#endif
