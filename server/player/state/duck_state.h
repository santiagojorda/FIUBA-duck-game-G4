#ifndef DUCK_STATE_H
#define DUCK_STATE_H

#include <cstdint>
#include <string>
#include "../../../common/state_duck.h"
#include "../../game/game_physics.h"
class Player;

class DuckState {
private:
protected:
    DuckStateType state_id;
    std::string state_name;
    uint8_t tick;
    uint8_t frame;
    uint8_t max_frames;
    uint8_t player_id;
    void reset();

public:
    DuckState(const DuckStateType& _state_id, const std::string& _state_name,const  uint8_t& _max_frames, const uint8_t& _player_id);
    virtual void update(Player& player, GamePhysics& physics);
    virtual void execute(Player& player, GamePhysics& physics);
    DuckStateType get_id();
    uint8_t get_frame();
    virtual ~DuckState() = default;
};

#endif