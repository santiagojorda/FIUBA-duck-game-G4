#include "duck_state_recoiling.h"

struct RecoilingStateConfig {
    DuckStateType id = DuckStateType::IS_RECOILING; 
    std::string name = "Recoiling"; 
};
RecoilingStateConfig recoiling_config;
DuckStateRecoiling::DuckStateRecoiling(): DuckState(recoiling_config.id, recoiling_config.name){}
void DuckStateRecoiling::update(Player& player) {
    (void)player;
    
} 
DuckStateRecoiling::~DuckStateRecoiling() {}
