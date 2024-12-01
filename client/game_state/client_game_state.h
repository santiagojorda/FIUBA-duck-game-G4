#ifndef CLIENT_GAME_STATE_H
#define CLIENT_GAME_STATE_H

#include "elements.h"
#include "vector_floor_sprite.h"
#include "vector_player.h"
#include "vector_sprite.h"
#include "vector_guns.h"
#include "../../common/game_moment.h"

struct client_game_state_t {
    GameMoment moment;
    VectorPlayers players;
    std::vector<bullet_t> bullets;
    std::vector<box_t> boxs;
    VectorFloorSprite floors;
    VectorGuns weapons;
};

#endif  // CLIENT_GAME_STATE_H
