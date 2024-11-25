#ifndef STATE_H
#define STATE_H

#include <cstdint>
#include <string>

class Positionable;
class GamePhysics;

template <typename T>
class State {
protected:
    T state_id;
    std::string state_name;

public:
    State(const T& _state_id, const std::string& _state_name) 
        : state_id(_state_id), state_name(_state_name)
        {}

    virtual void update_state(Positionable& positionable, GamePhysics& physics) = 0;
    virtual void execute(Positionable& positionable, GamePhysics& physics) = 0;

    virtual uint8_t get_frame() = 0;
    virtual Direction get_direction() = 0;
    virtual void set_direction(const Direction& new_direction) = 0;

    virtual void start() {}
    virtual void finish() {}
    T get_id() { return state_id; }
    virtual ~State() {}
};

#endif

