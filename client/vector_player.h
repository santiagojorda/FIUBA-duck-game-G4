#ifndef VECTOR_PLAYER_H
#define VECTOR_PLAYER_H

#include <vector>

#include "sprite.h"

struct player_t {
    srprite_t sprite;
    uint8_t is_looking;
    uint8_t frame;
    inventory_t inventory;
};

struct inventory_t {
    srprite_t weapon;
    uint8_t ammo;
    srprite_t armor;
    srprite_t helmet;
};

class VecotorPlayers: public std::vector<player_t> {
private:
public:
    VecotorPlayers();
    ~VecotorPlayers();
};

VecotorPlayers::VecotorPlayers() {}

VecotorPlayers::~VecotorPlayers() {}

#endif  // VECTOR_PLAYER_H
