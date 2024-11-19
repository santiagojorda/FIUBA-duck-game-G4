#ifndef STATE_DUCK_H
#define STATE_DUCK_H

#include <cstdint>
#include <unordered_map>

enum DuckState : uint8_t {
    IS_JUMPING,
    IS_RUNNING,
    IS_CROUCHING,
    IS_RECOILING,
    IS_FALLING,
    IS_SLIPPING,
    IS_PLANING,
    IS_IDLE,
    IS_DEAD
};

struct DuckStateInfo_t {
    uint8_t max_frames;
    uint8_t frame_duration;
};

// Mapa que asocia el estado con su información de frames
extern std::unordered_map<DuckState, DuckStateInfo_t> duck_state_frames;

#endif
