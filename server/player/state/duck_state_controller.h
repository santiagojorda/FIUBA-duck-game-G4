#ifndef DUCK_STATE_CONTROLLER_H
#define DUCK_STATE_CONTROLLER_H

#include <cstdint>
#include <map>
#include <string>

#include "../../../common/direction.h"
#include "../../../common/state_duck.h"

#include "duck_state.h"
#include "duck_state_factory.h"

class Player;
class GamePhysics;

class DuckStateController {
private:
    DuckStateFactory states;
    DuckState* current_state;
    Direction direction;
    void set_state(const DuckStateType& new_state);
    void set_direction(const Direction& new_direction);
    void execute(Player& player, GamePhysics& physics);
    void run(Direction direction, Player& player, GamePhysics& physics);

public:
    DuckStateController(const uint8_t& _player_id);

    void update(Player& player, GamePhysics& physics);
    void run_right(Player& player, GamePhysics& physics);
    void run_left(Player& player, GamePhysics& physics);
    void jump(Player& player, GamePhysics& physics);
    void fall(Player& player, GamePhysics& physics);
    void crouch(Player& player, GamePhysics& physics);
    void slip(Player& player, GamePhysics& physics);
    void recoil(Player& player, GamePhysics& physics);
    void plane(Player& player, GamePhysics& physics);
    void die(Player& player);
    void idle(Player& player);
    bool is_in_state(DuckStateType state);
    bool is_jumping();
    bool is_running();
    bool is_falling();
    bool is_idle();
    bool is_dead();


    Direction get_direction();
    DuckStateType get_state();
    uint8_t get_frame();

    ~DuckStateController();
};

#endif