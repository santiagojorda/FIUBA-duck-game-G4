#include "game_physics.h"

const int G_FORCE = 10;
#include <iostream>

GamePhysics::GamePhysics(Map& _map) : map(_map) {}

bool GamePhysics::collision(const Rectangle& a, const Rectangle& b) {
    // esto solo funciona para rectangulos en 2d no rotados
    return !(a.get_x_max() < (b.get_x_min() - 1) || a.get_x_min() > b.get_x_max() ||
             a.get_y_max() < (b.get_y_min() - 1) || a.get_y_min() > b.get_y_max());
}

void GamePhysics::falling(Positionable& target, uint iter_frame) {
    target.translate_y(iter_frame * iter_frame * (G_FORCE / 2));
}

GamePhysics::~GamePhysics() {}
