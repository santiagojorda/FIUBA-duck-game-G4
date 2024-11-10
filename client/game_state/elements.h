#include "sprite.h"
#ifndef ELEMENTS_H
#define ELEMENTS_H

struct bullet_t {
    sprite_t bullet;
    uint8_t frame;
};

struct box_t {
    sprite_t box;
    uint8_t frame;
};

#endif  // ELEMENTS_H
