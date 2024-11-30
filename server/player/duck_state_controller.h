#ifndef DUCK_STATE_CONTROLLER_H
#define DUCK_STATE_CONTROLLER_H

#include <cstdint>
#include <map>
#include <string>

#include "../../common/direction.h"
#include "../../common/state_duck.h"

#include "duck_state.h"
#include "duck_state_factory.h"

#include "../utils/state_controller.h"

class Player;
class GameLogic;

class DuckStateController : public StateController<DuckStateType> {
private:
    Direction direction;
    // uint8_t jump; // 0 -> control de cantidad de saltos
    bool touch_floor;
    void set_direction(const Direction& new_direction);
    void execute(Player& player, GameLogic& game_logic);
    void set_alive_state(const DuckStateType new_state_type);
    void execute_aero_running(Direction direction, Player& player, GameLogic& game_logic);

public:
    DuckStateController(const uint8_t& _player_id);

    void reset();

    void run(Direction direction, Player& player, GameLogic& game_logic);
    void run_right(Player& player, GameLogic& game_logic);
    void run_left(Player& player, GameLogic& game_logic);
    void jump(Player& player, GameLogic& game_logic);
    void fall(Player& player, GameLogic& game_logic);
    void crouch(Player& player, GameLogic& game_logic);
    void slip(Player& player, GameLogic& game_logic);
    void recoil(Player& player, GameLogic& game_logic);
    void plane(Player& player, GameLogic& game_logic);
    void die(Player& player);
    void idle(Player& player);
    bool is_jumping();
    bool is_running();
    bool is_falling();
    bool is_idle();
    bool is_dead() const;
    bool is_alive();
    bool is_dead_animation_finished() const;
    bool is_touching_floor();
    void set_touch_floor(const bool& _touch_floor);
    Direction get_direction();
    DuckStateType get_state();
    uint8_t get_frame() const;

    ~DuckStateController();
};

#endif