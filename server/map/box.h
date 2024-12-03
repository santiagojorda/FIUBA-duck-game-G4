#ifndef BOX_H
#define BOX_H

#include <cstdint>
#include "../../common/boxes_id.h"
#include "../attributes/positionable.h"
#include "../attributes/collidable.h"

class Projectile;
class GameLogic;

enum GroundState : uint8_t{
    CLOSE = 0,
    OPEN = 1
};
class Box: public Positionable, public Collidable{
private:
    GroundState state;

public:
    explicit Box(const Coordinate& _coordinate);
    
    void handle_collision(std::shared_ptr<Collidable> other, GameLogic& game_logic) override;

    using Collidable::on_collision_with;
    void on_collision_with(std::shared_ptr<Projectile> projectile, GameLogic& game_logic) override;

    bool is_open();
    void open();
    void reset();
    uint8_t get_state();
};
#endif
