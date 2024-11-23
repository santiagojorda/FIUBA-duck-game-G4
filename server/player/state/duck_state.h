#ifndef DUCK_STATE_H
#define DUCK_STATE_H

#include <cstdint>
#include <string>

#include "../../../common/direction.h"
#include "../../../common/state_duck.h"
#include "../../game/game_physics.h"
class Player;

class DuckState {
protected:
    DuckStateType state_id;
    std::string state_name;
    uint8_t tick;
    uint8_t frame;
    uint8_t max_frames;
    uint8_t player_id;
    Direction direction;
    void reset();
    void init_state(const uint8_t& player_id);

public:
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,
              const uint8_t& _max_frames, const uint8_t& _player_id);
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,
              const uint8_t& _max_frames, const uint8_t& _player_id, const Direction& _direction);
    virtual void start();
    virtual void finish();
    virtual void set_direction(const Direction& _direction);
    virtual Direction get_direction();
    virtual void update(Player& player, GamePhysics& physics);
    virtual void execute(Player& player, GamePhysics& physics);
    DuckStateType get_id();
    uint8_t get_frame();
    virtual ~DuckState() = default;
};

#endif