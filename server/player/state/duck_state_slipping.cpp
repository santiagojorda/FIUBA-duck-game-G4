#include "duck_state_slipping.h"

struct SlippingStateConfig {
    DuckStateType id = DuckStateType::IS_SLIPPING; 
    std::string name = "Sliping"; 
};
SlippingStateConfig slipping_config;

DuckStateSlipping::DuckStateSlipping(const uint8_t& _player_id): 
    DuckState(slipping_config.id, slipping_config.name, duck_state_frames[slipping_config.id].max_frames, _player_id)
{}

DuckStateSlipping::~DuckStateSlipping() {}
