#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include <cstdint>

#include "../attributes/positionable.h"
#include "../attributes/statable.h"
#include "../attributes/equippable.h"
#include "../player/inventory.h"
#include "../guns/list_projectiles.h"
#include "../guns/gun.h"
#include "direction.h"


class Player: public Positionable, public Statable {
private:
    // cppcheck-suppress unusedStructMember
    uint8_t id;
    
    // cppcheck-suppress unusedStructMember
    Direction look_direction = Direction::RIGHT;
    
    Inventory inventory;

    void looks_up();
    void looks_right();
    void looks_left();
    

public:
    Player();
    explicit Player(uint8_t _id);
    Player& operator=(const Player& _other);
    uint8_t get_id() const;
    void translate() override;
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;
    void move_back(ShootingRecoil tiles);
    // void move_back(int tiles);
    Gun* get_gun();
    Armor* get_armor();
    Helmet* get_helmet();
    ListProjectiles shoot();
    void equip(Equippable* item);
    Direction get_direction();
    Inventory& get_inventory();

    virtual ~Player();
};

#endif  // SERVER_PLAYER_H_
