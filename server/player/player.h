#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include <cstdint>

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
#include "../attributes/statable.h"
#include "../guns/gun.h"
#include "../guns/list_projectiles.h"
#include "../player/inventory.h"
#include "../game/game_physics.h"

#include "direction.h"


class Player: public Positionable, public Statable {
private:
    // cppcheck-suppress unusedStructMember
    uint8_t health;  // te lo dejo para ir pensado en la vida
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
    void adjust_position_to_floor(Positionable* floor);
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;
    void move_back(ShootingRecoil tiles);
    // void move_back(int tiles);

    void update() override;
    Gun* get_gun();
    Armor* get_armor();
    Helmet* get_helmet();
    void shoot( ListProjectiles& projectiles);
    void equip(Equippable* item);
    Direction get_direction();
    Inventory& get_inventory();

    void run_right();
    void run_left();
    void jump();
    void fall(GamePhysics& physics);
    void crouch();
    void slip();
    void recoil();
    void plane();
    void die();
    void idle();

    bool is_jumping();

    virtual ~Player();
};

#endif  // SERVER_PLAYER_H_
