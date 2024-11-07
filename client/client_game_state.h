#ifndef CLIENT_GAME_STATE_H
#define CLIENT_GAME_STATE_H

#include "vector_player.h"
#include "vector_sprite.h"
#include "vector_throwable.h"


struct bullet_t {
    sprite_t bullet;
    uint8_t frame;
};

struct box_t {
    sprite_t box;
    uint8_t frame;
};

struct client_game_state_t {
    VectorPlayers players;
    std::vector<bullet_t> bullets;
    VectorThrowable throwable;
    std::vector<box_t> boxs;
    VectorSprite floors;
};


#endif  // CLIENT_GAME_STATE_H
