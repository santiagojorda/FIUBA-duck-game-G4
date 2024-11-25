#ifndef DUCK_STATE_JUMPING_H
#define DUCK_STATE_JUMPING_H

#include "../duck_state.h"

class DuckStateJumping: public DuckState {
public:
    DuckStateJumping(const uint8_t& _player_id);

    void update_state(Positionable& positionable, GamePhysics& physics) override;

    ~DuckStateJumping();
};

#endif
