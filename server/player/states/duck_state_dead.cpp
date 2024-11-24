#include "duck_state_dead.h"

struct DeadStateConfig {
    DuckStateType id = DuckStateType::DEAD;
    std::string name = "Dead";
};
DeadStateConfig dead_config;

DuckStateDead::DuckStateDead(const uint8_t& _player_id):
        DuckState(dead_config.id, dead_config.name, duck_state_frames[dead_config.id].max_frames,
                  _player_id) {}

DuckStateDead::~DuckStateDead() {}
