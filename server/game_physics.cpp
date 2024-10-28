#include "game_physics.h"

const int G_FORCE = 10;

bool collision_point(const int collision_point, const int collision_min, const int collision_max) {
    return (collision_min <= collision_point) && (collision_point <= collision_max);
}

bool GamePhysics::horizontal_touch(const Coordinate& a, const Coordinate& target) {
    return collision_point(a.get_x(), target.get_x(), target.get_x() + target.get_w());
}

bool GamePhysics::vertical_touch(const Coordinate& a, const Coordinate& target) {
    return collision_point(a.get_y(), target.get_y(), target.get_y() + target.get_h());
}

bool GamePhysics::inside(const Coordinate& a, const Coordinate& b) {
    return this->horizontal_touch(a, b) && this->vertical_touch(a, b);
}

bool GamePhysics::collision(const Coordinate& a, const Coordinate& b) {
    return this->inside(a, b) || this->inside(b, a);
}


void GamePhysics::faling(Coordinate& coordinate, uint iter_frame) {
    coordinate += Coordinate(0, (G_FORCE / 2) * iter_frame * iter_frame, 0, 0);
}
