#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include <cstdint>

#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
#include "../guns/gun.h"
#include "../guns/list_projectiles.h"
#include "../player/inventory.h"
#include "../game/game_physics.h"

#include "../../common/direction.h"
#include "state/duck_state_controller.h"

class Player: public Positionable {
private:
    // cppcheck-suppress unusedStructMember
    uint8_t health;  // te lo dejo para ir pensado en la vida
    // cppcheck-suppress unusedStructMember
    Direction look_direction = Direction::RIGHT;

    Inventory inventory;
    DuckStateController state;
    void looks_up();
    void looks_right();
    void looks_left();
    void log_action(const std::string& action);

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
    void update();
    
    Gun* get_gun();
    Armor* get_armor();
    Helmet* get_helmet();
    ListProjectiles shoot();
    void equip(Equippable* item);
    Direction get_direction();
    Inventory& get_inventory();

    void run_right();
    void run_left();
    void run(Direction& direction); 
    void jump();
    void fall(GamePhysics& physics);
    void crouch();
    void slip();
    void recoil();
    void plane();
    void die();
    void idle();

    bool is_jumping();
    bool is_dead();

    DuckStateType get_state();
    uint8_t get_frame();

    virtual ~Player();
};

#endif  // SERVER_PLAYER_H_
