#include "bullet_bounce.h"


BulletBounce::BulletBounce(const ProjectileRange& _range_tiles, const Coordinate& _coordinate):
        Bullet(_range_tiles, _coordinate) {}


void bounce(const Positionable& superfice) { (void)superfice; }

BulletBounce::~BulletBounce() {}
