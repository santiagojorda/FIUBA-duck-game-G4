#include "duck_state_slipping.h"

struct SlippingStateConfig {
    DuckStateType id = DuckStateType::IS_SLIPPING; 
    std::string name = "Sliping"; 
};
SlippingStateConfig slipping_config;

DuckStateSlipping::DuckStateSlipping(): DuckState(slipping_config.id, slipping_config.name){}

void DuckStateSlipping::update(Player& player) {
    (void)player;
    
} 
DuckStateSlipping::~DuckStateSlipping() {}
