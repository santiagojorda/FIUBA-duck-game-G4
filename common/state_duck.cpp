#include "state_duck.h"

// se agrego la cantidad de ticks por frame

std::unordered_map<DuckStateType, DuckStateInfo_t> duck_state_frames = {
        {DuckStateType::IS_JUMPING, {6}},   {DuckStateType::IS_RUNNING, {6}},
        {DuckStateType::IS_CROUCHING, {1}}, {DuckStateType::IS_RECOILING, {3}},
        {DuckStateType::IS_FALLING, {1}},   {DuckStateType::IS_SLIPPING, {2}},
        {DuckStateType::IS_PLANNING, {6}},   {DuckStateType::IS_IDLE, {1}},
        {DuckStateType::IS_DEAD, {1}}};