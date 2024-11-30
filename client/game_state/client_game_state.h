#ifndef CLIENT_GAME_STATE_H
#define CLIENT_GAME_STATE_H

#include "elements.h"
#include "vector_player.h"
#include "vector_sprite.h"
#include "vector_floor_sprite.h"
#include "vector_throwable.h"

struct client_game_state_t {
    VectorPlayers players;
    std::vector<bullet_t> bullets;
    VectorThrowable throwable;
    std::vector<box_t> boxs;
    VectorFloorSprite floors;
    VectorSprite weapons;
};

#endif  // CLIENT_GAME_STATE_H
