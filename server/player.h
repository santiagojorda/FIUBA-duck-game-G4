#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include "positionable.h"

class Player : protected Positionable {
private:
    uint8_t id;

public:
    explicit Player(uint8_t& _id);
    void translate() override;
    void translate_x() override;
    void translate_y() override;

    ~Player();
};

#endif
