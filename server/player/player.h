#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include <cstdint>

#include "../attributes/positionable.h"
// #include "../attributes/statable.h"
#include "../attributes/equippable.h"
#include "../player/inventory.h"

class Player: public Positionable {
private:
    // cppcheck-suppress unusedStructMember
    uint8_t id;
    Inventory inventory;

public:
    Player();
    explicit Player(uint8_t _id);
    Player& operator=(const Player& _other);
    uint8_t get_id() const;
    void translate() override;
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;
    // void move_back(int tiles);
    void equip(Equippable* item);
    virtual ~Player();
};

#endif  // SERVER_PLAYER_H_
