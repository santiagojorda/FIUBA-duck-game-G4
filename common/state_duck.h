#ifndef STATE_DUCK_COMMON_H
#define STATE_DUCK_COMMON_H

#include <cstdint>
#include <unordered_map>

enum class DuckStateType : uint8_t {
    IS_JUMPING,
    IS_RUNNING,
    IS_CROUCHING,
    IS_RECOILING,
    IS_FALLING,
    IS_SLIPPING,
    IS_PLANNING,
    IS_IDLE,
    IS_DEAD
};

struct DuckStateInfo_t {
    uint8_t max_frames;
};

// Mapa que asocia el estado con su información de frames
extern std::unordered_map<DuckStateType, DuckStateInfo_t> duck_state_frames;

#endif
