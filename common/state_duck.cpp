#include "state_duck.h"

std::unordered_map<DuckState, DuckStateInfo_t> duck_state_frames = {
        {IS_JUMPING, {6}},   {IS_RUNNING, {6}}, {IS_CROUCHING, {1}},
        {IS_RECOILING, {3}}, {IS_FALLING, {1}}, {IS_SLIPPING, {2}},
        {IS_PLANING, {6}},   {IS_IDLE, {1}},    {IS_DEAD, {1}}};