#ifndef DUCK_STATE_H
#define DUCK_STATE_H

#include <cstdint>
#include <string>

#include "../attributes/directionable.h"
#include "../attributes/updatable.h"
#include "../attributes/frameable.h"
#include "../../common/state_duck.h"
#include "../game/game_physics.h"
#include "../utils/state.h"

class Player;

class DuckState : public State<DuckStateType>, public Updatable  {
protected:
    // DuckStateType state_id;
    // std::string state_name;
    uint8_t player_id;
    Directionable direction_handler;
    Frameable frame_handler;
    void reset();
    void init_state(const uint8_t& player_id);

public:
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,
              const uint8_t& _max_frames, const uint8_t& _player_id);
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,
              const uint8_t& _max_frames, const uint8_t& _player_id, const Direction& _direction);
    virtual void start() override;
    virtual void finish() override;
    virtual void update_state(Positionable& positionable, GamePhysics& physics) override;
    virtual void execute(Positionable& positionable, GamePhysics& physics) override;
    
    Direction get_direction() override;
    void set_direction(const Direction& new_direction) override;
    uint8_t get_frame() override;
    virtual ~DuckState();
};

#endif