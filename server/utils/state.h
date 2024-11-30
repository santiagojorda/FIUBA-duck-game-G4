#ifndef STATE_H
#define STATE_H

#include <cstdint>
#include <string>

#include "../attributes/positionable.h"
#include "../attributes/frameable.h"

class GameLogic;

template <typename T>
class State : public Directionable, public Frameable{
protected:
    T state_id;
    std::string state_name;

public:
    State(const T& _state_id, const std::string& _state_name, const uint8_t& _max_frames, const Direction& _direction) 
        : Directionable(_direction), Frameable(_max_frames), state_id(_state_id), state_name(_state_name)
        {}

    virtual void update_state(Positionable& positionable, GameLogic& game_logic) = 0;
    virtual void execute(Positionable& positionable, GameLogic& game_logic) = 0;

    virtual void start() {}
    virtual void finish() {}
    virtual void reset() { Frameable::reset(); }
    T get_id() { return state_id; }
    virtual ~State() {}
};

#endif
