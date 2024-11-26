#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../attributes/positionable.h"
#include "../attributes/updatable.h"

#include "projectile_range.h"
#include "../attributes/directionable.h"
#include "../game/game_physics.h"


enum class ProjectileState: uint8_t {
    DEAD,
    ALIVE
    // THROWING,
};

class Projectile: public Positionable, public Directionable, public std::enable_shared_from_this<Projectile>  {  // es un statable
protected:
    ProjectileRange range_tiles;
    uint8_t count_tiles_moved;
    Direction direction;
    ProjectileState state;
    Updatable update_handler;
    

public:
    explicit Projectile(const uint8_t& texture_id, ProjectileRange _range_tiles,
                        Coordinate _coordinate, const Direction& _direction);
    virtual void update(GamePhysics& physics);
    bool is_dead();
};

#endif  // PROJECTILE_H
