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
class Box: public Positionable {
private:
    GroundState state;

public:
    explicit Box(const Coordinate& _coordinate);
    
    // void handle_collision(Collidable& other, GameLogic& game_logic) override;
    // void on_collision_with(Collidable& other, GameLogic& game_logic) override;
    // void on_collision_with(Projectile& projectile, GameLogic& game_logic);

    bool is_open();
    void open();
    void reset();
    uint8_t get_state();
};
#endif
