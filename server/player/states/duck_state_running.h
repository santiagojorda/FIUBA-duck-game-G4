#ifndef DUCK_STATE_RUNNING_H
#define DUCK_STATE_RUNNING_H

#include "../../../common/direction.h"
#include "../duck_state.h"
class DuckStateRunning: public DuckState {
private:
public:
    explicit DuckStateRunning(uint8_t _player_id);

    void update_state(Positionable& positionable, GamePhysics& physics) override;
    void execute(Positionable& positionable, GamePhysics& physics) override;
    void move(Positionable& positionable);

    ~DuckStateRunning();
};

#endif
