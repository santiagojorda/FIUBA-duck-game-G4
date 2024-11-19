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
    uint8_t player_id;
    void reset();

public:
    DuckState(const DuckStateType& _state_id, const std::string& _state_name, const Player& player);
    virtual void update(Player& player);
    DuckStateType get_id();
    uint8_t get_frame();
    virtual ~DuckState() = default;
};

#endif