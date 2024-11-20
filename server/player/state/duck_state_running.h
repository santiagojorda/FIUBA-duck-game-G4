#ifndef DUCK_STATE_RUNNING_H
#define DUCK_STATE_RUNNING_H

#include "duck_state.h"
#include "../../../common/direction.h"

class DuckStateRunning: public DuckState{
private:
    Direction& direction;
public:
    DuckStateRunning(const uint8_t& _player_id, Direction& _direction);

    void update(Player& player, GamePhysics& physics) override;
    void execute(Player& player, GamePhysics& physics) override;
    ~DuckStateRunning();
};

#endif
