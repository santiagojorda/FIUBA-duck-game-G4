#include "player.h"

#include <iostream>

#include "../guns/gun.h"

#include "../../common/state_duck.h"

const int SPEED = 1;
#define RUN_STEP 10
#define JUMP_STEP -10
#define FALLING_STEP 1

Player::Player(): Statable((uint8_t)DuckState::IS_IDLE) {}
Player::Player(uint8_t _id):
    Positionable(_id, Coordinate(10, 10, 32, 32)), 
    Statable(uint8_t(DuckState::IS_IDLE)) 
    {}

Player::~Player() { Positionable::~Positionable(); }

void Player::looks_right() { look_direction = Direction::RIGHT; }
void Player::looks_left() { look_direction = Direction::LEFT; }
void Player::looks_up() { look_direction = Direction::UP; }

void Player::update() {

    frame++;
    tick++;

    if (frame >= duck_state_frames[(DuckState)state].max_frames) {
        switch (state) {
            case DuckState::IS_FALLING:
                reset();
                break;

            case DuckState::IS_IDLE:
                reset();
                break;

            case DuckState::IS_JUMPING:
                set_state(DuckState::IS_FALLING);
                break;                

            case DuckState::IS_DEAD:
                reset();
                break;
            default:
                idle();
        }
    }
}

void Player::log_action(const std::string& action) {
    std::cout << "Player " << int(id) << " " << action << std::endl;
}


void Player::run_right() {
    if (state != DuckState::IS_RUNNING) {
        set_state(DuckState::IS_RUNNING);
        log_action("Runs to the right");
    }
    translate_x(RUN_STEP);
}
void Player::run_left() {
    if (state != DuckState::IS_RUNNING) {
        set_state(DuckState::IS_RUNNING);
        log_action("Runs to the left");
    }
    translate_x(-RUN_STEP);
}
void Player::jump() {
    if (state != DuckState::IS_JUMPING) {
        set_state(DuckState::IS_JUMPING);        
        log_action("Jumps");

    }

    translate_y(JUMP_STEP);
}
void Player::fall(GamePhysics& physics) {
    if (state != DuckState::IS_FALLING) {
        set_state(DuckState::IS_FALLING);

    }
    physics.falling(*this, 1);
    log_action("Fall");
}
void Player::crouch() {
    if (state != DuckState::IS_CROUCHING) {
        set_state(DuckState::IS_CROUCHING);
        log_action("Crouches");
    }
    // translate_y(1); // esto no deberia moverse
}
void Player::slip() { 
    if(state != DuckState::IS_SLIPPING){
        set_state(DuckState::IS_SLIPPING); 
        log_action("Slips");
    }
}
void Player::recoil() { 
    if(state != DuckState::IS_RECOILING){
        set_state(DuckState::IS_RECOILING); 
        log_action("Recoils");
    }
}
void Player::plane() { 
    if(state != DuckState::IS_PLANING){
        set_state(DuckState::IS_PLANING);
        log_action("Plans");
    }
}
void Player::die() { 
    if(state != DuckState::IS_DEAD){
        set_state(DuckState::IS_DEAD); 
        log_action("Deads");
    }
}
void Player::idle() { 
    if(state != DuckState::IS_IDLE){
        set_state(DuckState::IS_IDLE);
        log_action("Idle");
    }
}

uint8_t Player::get_id() const { return this->id; }
Gun* Player::get_gun() { return inventory.get_gun(); }
Armor* Player::get_armor() { return inventory.get_armor(); }
Helmet* Player::get_helmet() { return inventory.get_helmet(); }
Inventory& Player::get_inventory() { return inventory; }
Direction Player::get_direction() { return look_direction; }

void Player::adjust_position_to_floor(Positionable* floor){
    if(floor){

        int player_bottom = space.get_y_max();
        Rectangle floor_points = floor->get_rectangle();
        int floor_top = floor_points.get_y_min();
        int difference = player_bottom - floor_top;

        if (difference < 1) {
            translate_y(-(difference + 1));
        }
        else {
            translate_y(-(difference - 1)); 
        }
    }
}

void Player::translate() {}

void Player::translate_x(int pasos) {  // cambiar la variable
    if (pasos > 0) {
        looks_right();
    } else if (pasos < 0) {
        looks_left();
    }

    Rectangle new_pos(this->space.get_coordinates() + Coordinate(pasos * SPEED, 0, 0, 0));
    this->space = new_pos;
}

void Player::translate_y(int pasos) {  // cambiar la variable
    Rectangle new_pos(this->space.get_coordinates() + Coordinate(0, pasos * SPEED, 0, 0));
    this->space = new_pos;
}

Player& Player::operator=(const Player& _other) {
    this->id = _other.id;
    this->space = _other.space;
    return *this;
}

void Player::equip(Equippable* item) { inventory.equip(item); }

void Player::move_back(ShootingRecoil tiles) {
    // if(look_direction == Direction::LEFT){
    //     translate_x()
    // }
    // else{
    //     translate_x();
    // }

    // esto tiene que ser de forma iterativa -> stado

    (void)tiles;
}

bool Player::is_jumping(){ return state == DuckState::IS_JUMPING; }
bool Player::is_dead(){ return state == DuckState::IS_DEAD; }

ListProjectiles Player::shoot() {
    Gun* gun = inventory.get_gun();
    if (!gun) {
        return ListProjectiles();
    }

    Coordinate actual_position = get_coordinate();
    ShootingRecoil recoil;
    ListProjectiles projectiles = gun->shoot(actual_position, recoil);
    if ((int)recoil > 0) {  // is there recoil? yes -> it could be a function
        move_back(recoil);
    }
    return projectiles;
}

// --------------------- STATE
