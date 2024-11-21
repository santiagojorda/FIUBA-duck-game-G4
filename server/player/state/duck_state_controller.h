#ifndef DUCK_STATE_CONTROLLER_H
#define DUCK_STATE_CONTROLLER_H

#include <cstdint>
#include <string>
#include "../../../common/state_duck.h"
#include "../../../common/direction.h"
#include "duck_state.h"

#include "duck_state_crouching.h"
#include "duck_state_dead.h"
#include "duck_state_falling.h"
#include "duck_state_idle.h"
#include "duck_state_jumping.h"
#include "duck_state_planning.h"
#include "duck_state_recoiling.h"
#include "duck_state_running.h"
#include "duck_state_slipping.h"

class Player;
class GamePhysics;

class DuckStateController {
private:
    DuckState* current_state;
    Direction direction;
    void set_state(DuckState* new_state);

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