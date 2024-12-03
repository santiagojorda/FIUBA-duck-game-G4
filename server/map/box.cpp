#include "box.h"

#include <iostream>

#include "../weapons/projectile.h"
#include "../game/game_logic.h"

Box::Box(const Coordinate& _coordinate)
: Positionable((uint8_t)BoxesTextureID::DEFAULT, _coordinate),
        state(GroundState::CLOSE)
    {}

void Box::handle_collision(std::shared_ptr<Collidable> other, GameLogic& game_logic) {
    std::cout << "Handling collision with box" << std::endl;
    other->on_collision_with(std::dynamic_pointer_cast<Box>(shared_from_this()), game_logic);
}

void Box::on_collision_with(std::shared_ptr<Projectile> projectile, GameLogic& game_logic) {
    std::cout << "Box collided with projectile" << std::endl;
    projectile->on_collision_with(std::dynamic_pointer_cast<Box>(shared_from_this()), game_logic);
    open();
}

void Box::reset() { state = GroundState::CLOSE; }
bool Box::is_open() { return state == GroundState::OPEN; }
void Box::open() { state = GroundState::OPEN; }
uint8_t Box::get_state() { return (uint8_t)state; }
