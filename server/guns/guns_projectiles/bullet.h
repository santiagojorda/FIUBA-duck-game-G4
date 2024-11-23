#ifndef BULLET
#define BULLET

#include "../projectile.h"
#include "../../game/game_physics.h"

#define MAX_RANGE_TILES 1  // medio

class Bullet: public Projectile {
private:
    double dispersion_angle; // radianes
    uint8_t tick = 0;
public:
    explicit Bullet(const ProjectileRange& _range_tiles, const Coordinate& _coordinate, const Direction& _direction, const int& _dispersion_angle);
    void update(GamePhysics& physics) override;
};

#endif
