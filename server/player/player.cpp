#include "player.h"

#include <iostream>

#include "../../common/state_duck.h"
#include "../weapons/gun.h"
#include "../game/game_logic.h"
#include "../weapons/list_projectiles.h"

const int SPEED = 1;
#define RUN_STEP 10
#define JUMP_STEP -40
#define FALLING_STEP 1

Player::Player(uint8_t _id): Positionable(_id, _id, Coordinate(10, 10, 32, 32)), state(id), touch_floor(false) {}

Player::~Player() { Positionable::~Positionable(); }

void Player::update(GameLogic& game_logic) {     
    state.update(*this, game_logic); 
}

void Player::log_action(const std::string& action) {
    std::cout << "Player " << int(id) << " " << action << std::endl;
}

void Player::run_right(GameLogic& game_logic) { state.run_right(*this, game_logic); }
void Player::run_left(GameLogic& game_logic) { state.run_left(*this, game_logic); }
void Player::jump(GameLogic& game_logic) { state.jump(*this, game_logic); }
void Player::fall(GameLogic& game_logic) { state.fall(*this, game_logic); }
void Player::crouch(GameLogic& game_logic) { state.crouch(*this, game_logic); }
void Player::slip(GameLogic& game_logic) { state.slip(*this, game_logic); }
void Player::recoil(GameLogic& game_logic) { state.recoil(*this, game_logic); }
void Player::plane(GameLogic& game_logic) { state.plane(*this, game_logic); }
void Player::idle() { state.idle(*this); }
void Player::die(GameLogic& game_logic) {
    health = 0;
    drop_gun(game_logic);
    state.die(*this);
}

void Player::reset(){
    this->state.reset();
    this->inventory.reset();
}

void Player::equip(std::shared_ptr<Equippable> item) { inventory.equip(item); }

void Player::update_gun_position(){
    std::shared_ptr<Gun> gun = inventory.get_gun();
    if (!gun) {
        return;
    }
    gun->set_coordinate(this->get_coordinate());
    gun->set_direction(this->get_direction());
}

void Player::drop_gun(GameLogic& game_logic){ 
    update_gun_position();
    inventory.drop_gun(game_logic); 
}
void Player::drop_armor(){ 
    inventory.drop_armor(); 
}
void Player::drop_helmet(){ 
    inventory.drop_helmet(); 
}

uint8_t Player::get_id() const { return this->id; }
std::shared_ptr<Gun> Player::get_gun() { return inventory.get_gun(); }
std::shared_ptr<Armor> Player::get_armor() { return inventory.get_armor(); }
std::shared_ptr<Helmet> Player::get_helmet() { return inventory.get_helmet(); }
Inventory& Player::get_inventory() { return inventory; }
Direction Player::get_direction() { return state.get_direction(); }

void Player::adjust_position_to_floor(std::shared_ptr<Positionable> floor) {
    if (floor) {

        int player_bottom = space.get_y_max();
        Rectangle floor_points = floor->get_rectangle();
        int floor_top = floor_points.get_y_min();
        int difference = player_bottom - floor_top;

        if (difference < 1) {
            translate_y(-(difference + 1));
        } else {
            translate_y(-(difference - 1));
        }
    }
}



void Player::translate_x(int pasos) {
    int boost_speed = 1;
    Positionable::translate_x(pasos*boost_speed);
}

void Player::translate_y(int pasos) {
    int boost_speed = 1; // si queremos 
    Positionable::translate_y(pasos*boost_speed);
}

Player& Player::operator=(const Player& _other) {
    this->id = _other.id;
    this->space = _other.space;
    this->idle();
    return *this;
}

void Player::move_back(ShootingRecoil tiles) { (void)tiles; }

bool Player::is_jumping() { return state.is_jumping(); }
bool Player::is_running() { return state.is_running(); }
bool Player::is_falling() { return state.is_falling(); }
bool Player::is_idle()  { return state.is_idle(); }
bool Player::is_dead() const { return state.is_dead(); }
bool Player::is_alive() { return state.is_alive(); }

DuckStateType Player::get_state() { return state.get_state(); }

uint8_t Player::get_frame() { return state.get_frame(); }
bool Player::has_equipped_this(std::shared_ptr<Equippable> item){
    return inventory.has_equipped_this(item);
}
bool Player::is_touching_floor() { return touch_floor; }
void Player::set_touching_floor(const bool& new_touch) { touch_floor = new_touch; }

void Player::shoot(ListProjectiles& projectiles, const ModeShoot& mode) {
    std::shared_ptr<Gun> gun = inventory.get_gun();
    if (!gun) {
        return;
    }
    update_gun_position();
    ShootingRecoil recoil = gun->get_recoil();
    switch (mode)  {
        case ModeShoot::TRIGGER:
            gun->trigger(projectiles, id);
            break;
        case ModeShoot::TRIGGER_OUT:
            gun->trigger_out(projectiles, id);
            break;
        default:
            break;
    }
    if ((int)recoil > 0) {  // is there recoil? yes -> it could be a function
        move_back(recoil);
    }
}
