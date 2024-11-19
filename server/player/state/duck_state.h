#ifndef DUCK_STATE_H
#define DUCK_STATE_H

#include <cstdint>
#include <string>
#include "../../../common/state_duck.h"
class Player;

class DuckState {
private:
protected:
    DuckStateType state_id;
    std::string state_name;
    uint8_t tick;
    uint8_t frame;
    uint8_t max_frame;
    void reset() {
        tick = 0;
        frame = 0;
    }
public:
    DuckState(const DuckStateType& _state_id, const std::string& _state_name): 
        state_id(_state_id),
        state_name(_state_name)
        {
            reset();
        }
    virtual void update(Player& duck) = 0;
    DuckStateType get_id() { return state_id; }
    uint8_t get_frame() { return frame; }
    virtual ~DuckState() = default;
};

#endif