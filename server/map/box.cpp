#include "box.h"

#include <iostream>

#include "../weapons/projectile.h"
#include "../game/game_logic.h"

Box::Box(const Coordinate& _coordinate)
: Positionable((uint8_t)BoxesTextureID::DEFAULT, _coordinate),
        state(GroundState::CLOSE)
    {}


void Box::handle_collision(Projectile& projectile,GameLogic& game_logic) {
    (void)projectile;
    (void)game_logic;
    open();

    // decidir por un equipable
    // game_logic.handle_drop();
}

void Box::reset() { state = GroundState::CLOSE; }
bool Box::is_open() { return state == GroundState::OPEN; }
void Box::open() { state = GroundState::OPEN; }
uint8_t Box::get_state() { return (uint8_t)state; }
