#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../attributes/positionable.h"

#include "projectile_range.h"
#include "../../common/direction.h"
#include "../game/game_physics.h"

class Projectile: public Positionable {  // es un statable
protected:
    ProjectileRange range_tiles;
    Direction direction;

public:
    explicit Projectile(const uint8_t& texture_id, ProjectileRange _range_tiles,
                        Coordinate _coordinate, const Direction& _direction);
    virtual void update(GamePhysics& physics);
};

#endif  // PROJECTILE_H
