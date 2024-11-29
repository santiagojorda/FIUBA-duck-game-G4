#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include <cstdint>

#include "../../common/direction.h"
#include "../attributes/equippable.h"
#include "../attributes/positionable.h"
#include "../game/game_logic.h"
#include "inventory.h"
#include "../weapons/gun.h"
#include "../weapons/list_projectiles.h"
// #include "duck_state_controller.h"3
#include "duck_state_controller.h"
#include "../weapons/mode_shoot.h"

class GameLogic;

class Player: public Positionable {
private:
    // cppcheck-suppress unusedStructMember
    uint8_t health;  // te lo dejo para ir pensado en la vida
    Inventory inventory;
    DuckStateController state;
    void log_action(const std::string& action);
    bool touch_floor;
    void update_gun_position();

public:
    explicit Player(uint8_t _id);
    Player& operator=(const Player& _other);
    uint8_t get_id() const;
    void adjust_position_to_floor(std::shared_ptr<Positionable> floor);
    void translate_x(int pasos) override;
    void translate_y(int pasos) override;
    void move_back(ShootingRecoil tiles);


    std::shared_ptr<Gun> get_gun();
    std::shared_ptr<Armor> get_armor();
    std::shared_ptr<Helmet> get_helmet();

    void shoot(ListProjectiles& projectiles, const   ModeShoot&  mode);

    void equip(std::shared_ptr<Equippable> item);
    Direction get_direction();
    Inventory& get_inventory();

    void update(GameLogic& game_logic);
    void run_right(GameLogic& game_logic);
    void run_left(GameLogic& game_logic);
    void jump(GameLogic& game_logic);
    void fall(GameLogic& game_logic) override;
    void crouch(GameLogic& game_logic);
    void slip(GameLogic& game_logic);
    void recoil(GameLogic& game_logic);
    void plane(GameLogic& game_logic);
    void die();
    void idle();
    void drop_gun(GameLogic& game_logic);
    void drop_armor();
    void drop_helmet();
    void drop_gun(GameLogic& game_logic);
    void drop_armor();
    void drop_helmet();

    bool is_jumping();
    bool is_running();
    bool is_falling();
    bool is_idle();
    bool is_dead();
    bool is_touching_floor();
    void set_touching_floor(const bool& new_touch);

    bool has_equipped_this(std::shared_ptr<Equippable> item);
    DuckStateType get_state();
    uint8_t get_frame();

    virtual ~Player();
};

#endif  // SERVER_PLAYER_H_
