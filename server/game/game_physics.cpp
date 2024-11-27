#include "game_physics.h"

#include <iostream>
#include "../player/player.h"

GamePhysics::GamePhysics(Map& _map): map(_map) {}

bool GamePhysics::collision(const Rectangle& a, const Rectangle& b) {
    // esto solo funciona para rectangulos en 2d no rotados
    return !(a.get_x_max() < (b.get_x_min()) || a.get_x_min() > b.get_x_max() ||
             a.get_y_max() < (b.get_y_min()) || a.get_y_min() > b.get_y_max());
}

void GamePhysics::falling(Positionable& target, uint iter_frame) {
    target.translate_y(iter_frame * iter_frame * (G_FORCE / 2));
}

std::shared_ptr<Positionable> GamePhysics::get_player_floor_collision(Player& player) {
    for (auto& tile: this->map) {
        if (this->collision(player.get_rectangle(), tile->get_rectangle())) {
            // player.set_touching_floor(IS_TOUCHING_FLOOR);
            return tile;
        }
    }
    return nullptr;
}

bool GamePhysics::is_player_out_of_map(Player& player) {
    Rectangle player_space = player.get_rectangle();
    if (player_space.get_x_max() < 0 || player_space.get_y_max() < 0 ||
        player_space.get_x_min() > GAME_WIDTH || player_space.get_y_min() > GAME_HEIGHT) {
        return true;
    }
    return false;
}


void GamePhysics::update_player_gravity(Player& player) {
    std::shared_ptr<Positionable> touched_floor = get_player_floor_collision(player);
    if (touched_floor) {
        player.adjust_position_to_floor(touched_floor);
        if (player.is_falling()) {
            player.idle();
        }
    } else {
        player.fall(*this);
        // player.set_touching_floor(!IS_TOUCHING_FLOOR);
    }
}



GamePhysics::~GamePhysics() {}
