#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include <cstdint>
#include "../common/coordinate.h"

struct PlayerPosition_t {
    uint8_t id_player;
    Coordinate coordinate;
};

#endif  // PLAYER_POSITION_H
