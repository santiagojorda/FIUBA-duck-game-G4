#ifndef VECTOR_PLAYER_H
#define VECTOR_PLAYER_H

#include <vector>

#include "sprite.h"

struct inventory_t {
    sprite_t weapon;  // si es 0, dejo de leer y salto a armor
    uint8_t ammo;
    sprite_t armor;  // si es 0, dejo de leer y salto a helmet
    sprite_t helmet;
};

struct player_t {
    sprite_t sprite;
    uint8_t is_looking;
    uint8_t state;
    uint8_t frame;
    inventory_t inventory;
};

class VectorPlayers: public std::vector<player_t> {
private:
public:
    VectorPlayers();
    ~VectorPlayers();
};

#endif  // VECTOR_PLAYER_H
