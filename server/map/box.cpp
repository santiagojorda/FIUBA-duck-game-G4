#include "box.h"

#include <iostream>

#include "../weapons/projectile.h"
#include "../game/game_logic.h"

Box::Box(const Coordinate& _coordinate)
: Positionable((uint8_t)BoxesTextureID::DEFAULT, _coordinate),
        state(GroundState::CLOSE)
    {}

// void Box::handle_collision(Collidable& other, GameLogic& game_logic) {  
//     other.on_collision_with(*this, game_logic); 
// }

// void Box::on_collision_with(Collidable& other, GameLogic& game_logic) { 
//     std::cout << "Collision box con projectile" << std::endl;
//     other.on_collision_with(*this, game_logic); 

// }

// void Box::on_collision_with(Projectile& projectile, GameLogic& game_logic) { 
//     std::cout << "Collision box con projectile" << std::endl;
//     (void)projectile; 
//     (void)game_logic;
// }
void Box::reset() { state = GroundState::CLOSE; }
bool Box::is_open() { return state == GroundState::OPEN; }
void Box::open() { state = GroundState::OPEN; }
uint8_t Box::get_state() { return (uint8_t)state; }
