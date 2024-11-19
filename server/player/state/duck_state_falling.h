#ifndef DUCK_STATE_FALLING_H
#define DUCK_STATE_FALLING_H

#include "duck_state.h"
#include "../../game/game_physics.h"

class DuckStateFalling: public DuckState{
private:
    GamePhysics& physics;
public:
    DuckStateFalling(Player& _player, GamePhysics& _game_physics);

    void update(Player& player) override;
    ~DuckStateFalling();
};

#endif
