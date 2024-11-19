#include "duck_state_recoiling.h"

struct RecoilingStateConfig {
    DuckStateType id = DuckStateType::IS_RECOILING; 
    std::string name = "Recoiling"; 
};
RecoilingStateConfig recoiling_config;
DuckStateRecoiling::DuckStateRecoiling(Player& _player): DuckState(recoiling_config.id, recoiling_config.name, _player){}
void DuckStateRecoiling::update(Player& player) {
    (void)player;
    
} 
DuckStateRecoiling::~DuckStateRecoiling() {}
