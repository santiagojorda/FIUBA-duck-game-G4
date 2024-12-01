#include "bullet_bounce.h"


BulletBounce::BulletBounce(const ProjectileRange& _range_tiles, const Coordinate& _coordinate,
                           const Direction& _direction, const int& _dispersion_angle,
                           const uint8_t& _shooter_id):
        Bullet(_range_tiles, _coordinate, _direction, _dispersion_angle, _shooter_id) {}


void BulletBounce::bounce(const Positionable& surface) { (void)surface; }

void BulletBounce::collision_surface(Positionable& surface, GameLogic& game_logic) {
    (void)surface;
    (void)game_logic;
    this->dispersion_angle += 180;
}

BulletBounce::~BulletBounce() {}
