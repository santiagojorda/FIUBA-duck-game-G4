#include "duck_state_slipping.h"

struct SlippingStateConfig {
    DuckStateType id = DuckStateType::IS_SLIPPING; 
    std::string name = "Sliping"; 
};
SlippingStateConfig slipping_config;

DuckStateSlipping::DuckStateSlipping(Player& _player): DuckState(slipping_config.id, slipping_config.name, _player){}

void DuckStateSlipping::update(Player& player) {
    (void)player;
    
} 
DuckStateSlipping::~DuckStateSlipping() {}
