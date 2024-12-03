#ifndef GRANADE_H
#define GRANADE_H

#include "../gun.h"

class Inventory;

class Granade: public Gun {

public:
    explicit Granade(const Coordinate& _coordinate);

    void trigger(ListProjectiles& projectiles, const uint8_t& player_id) override;
    void update(GameLogic& game_logic) override;

    void trigger_out(ListProjectiles& projectiles, const uint8_t& player_id,
                     bool& was_dropped) override;
    void handle_explotion(GameLogic& game_logic) override;
    void handle_equip(Inventory& inventory) override;

    ~Granade();
};

#endif
