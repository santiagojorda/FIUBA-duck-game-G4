#include "state_duck.h"

// se agrego la cantidad de ticks por frame

std::unordered_map<DuckState, DuckStateInfo_t> duck_state_frames = {
        {IS_JUMPING, {6, 3}},   {IS_RUNNING, {6, 1}}, {IS_CROUCHING, {1, 1}},
        {IS_RECOILING, {3, 3}}, {IS_FALLING, {1, 3}}, {IS_SLIPPING, {2, 1}},
        {IS_PLANING, {6, 3}},   {IS_IDLE, {1, 1}},    {IS_DEAD, {1, 1}}};