#ifndef BOX_H
#define BOX_H

#include <cstdint>
#include "../../common/boxes_id.h"
#include "../attributes/positionable.h"

class Projectile;
class GameLogic;

enum GroundState : uint8_t{
    CLOSE,
    OPEN
};
class Box: public Positionable {
private:
    uint8_t state;

public:
    explicit Box(const Coordinate& _coordinate);
    
    using Positionable::handle_collision;
    void handle_collision(Projectile& projectile,GameLogic& game_logic) override;
    bool is_open();
    void open();
    uint8_t get_state();
};
#endif
