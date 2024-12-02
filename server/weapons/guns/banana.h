#ifndef BANANA_H
#define BANANA_H

#include "../gun.h"

class Banana: public Gun {
private:
    bool is_ready_to_slide;
public:
    explicit Banana(const Coordinate& _coordinate);

    void trigger_out(ListProjectiles& projectiles, const uint8_t& player_id,
                     bool& was_dropped) override;
    using Positionable::handle_collision;
    void handle_collision(Player& player, GameLogic& game_logic) override;

    ~Banana();
};

#endif
