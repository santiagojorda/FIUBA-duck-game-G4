#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../attributes/positionable.h"
#include "../attributes/updatable.h"

#include "projectile_range.h"
#include "../attributes/directionable.h"
class GameLogic;

enum class ProjectileState: uint8_t {
    DEAD,
    ALIVE
    // THROWING,
};

class Projectile: public Positionable, public Directionable, public std::enable_shared_from_this<Projectile> {  // es un statable
protected:
    ProjectileRange range_tiles;
    uint8_t count_tiles_moved;
    Direction direction;
    ProjectileState state;
    Updatable update_handler;
    uint8_t shooter_id;

public:
    explicit Projectile(const uint8_t& texture_id, ProjectileRange _range_tiles,
                        Coordinate _coordinate, const Direction& _direction, const uint8_t& _shooter_id);
    virtual void update(GameLogic& game_logic);
    void die();
    bool is_dead();
    virtual void collision_surface(Positionable& surface, GameLogic& game_logic);
    uint8_t get_shooter_id();
};

#endif  // PROJECTILE_H
