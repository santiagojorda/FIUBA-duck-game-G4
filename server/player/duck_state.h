#ifndef DUCK_STATE_H
#define DUCK_STATE_H

#include <cstdint>
#include <string>

#include "../attributes/directionable.h"
#include "../attributes/updatable.h"
#include "../attributes/frameable.h"
#include "../../common/state_duck.h"
#include "../utils/state.h"

class GameLogic;
class Player;

class DuckState : public State<DuckStateType>, public Updatable  {
protected:
    uint8_t player_id;
    void reset() override;
    void init_state(const uint8_t& player_id);

public:
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,
              const uint8_t& _max_frames, const uint8_t& _player_id);
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,
              const uint8_t& _max_frames, const uint8_t& _player_id, const Direction& _direction);
    virtual void start() override;
    virtual void finish() override;
    virtual void update_state(Positionable& positionable, GameLogic& game_logic) override;
    virtual void execute(Positionable& positionable, GameLogic& game_logic) override;
    
    virtual ~DuckState();
};

#endif