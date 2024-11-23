#include "duck_state_recoiling.h"

struct RecoilingStateConfig {
    DuckStateType id = DuckStateType::RECOILING;
    std::string name = "Recoiling";
};
RecoilingStateConfig recoiling_config;
DuckStateRecoiling::DuckStateRecoiling(const uint8_t& _player_id):
        DuckState(recoiling_config.id, recoiling_config.name,
                  duck_state_frames[recoiling_config.id].max_frames, _player_id) {}

DuckStateRecoiling::~DuckStateRecoiling() {}
