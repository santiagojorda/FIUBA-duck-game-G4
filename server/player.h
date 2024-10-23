#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include "positionable.h"

class Player : public Positionable {
private:
    uint8_t id;

public:
    Player(uint8_t& id);
    void translate() override;
    void translate_x() override;
    void translate_y() override;
};

#endif
