#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include <cstdint>

#include "positionable.h"

class Player: public Positionable {
private:
    uint8_t id;

public:
    Player();
    explicit Player(uint8_t _id);
    uint8_t get_id() const;
    void translate() override;
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;

    virtual ~Player();
};

#endif  // SERVER_PLAYER_H_
