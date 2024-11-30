#include "bullet_bounce.h"


BulletBounce::BulletBounce(const ProjectileRange& _range_tiles, const Coordinate& _coordinate):
        Bullet(_range_tiles, _coordinate, Direction::RIGHT, 0, 0) {}  // cambiar


void bounce(const Positionable& superfice) { (void)superfice; }

BulletBounce::~BulletBounce() {}
