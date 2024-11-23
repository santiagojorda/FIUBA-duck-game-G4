#include "game_logic.h"

#include <iostream>

#include "../../common/state_duck.h"

#define GAME_WIDTH 800
#define GAME_HEIGHT 500

GameLogic::GameLogic(ListPlayers& _players, Map& _map, ListGuns& _map_guns,
                     ListProjectiles& _map_projectiles):
        players(_players),
        map(_map),
        map_guns(_map_guns),
        map_projectiles(_map_projectiles),
        physics(map) {}

Positionable* GameLogic::get_player_floor_collision(const Player& player) {
    for (auto& tile: this->map) {
        if (this->physics.collision(player.get_rectangle(), tile->get_rectangle())) {
            return tile;
        }
    }
    return nullptr;
}

void GameLogic::update_player_equip_collision(Player& player) {
    for (auto& gun: map_guns.get_items()) {
        if (this->physics.collision(player.get_rectangle(), gun->get_rectangle())) {
            player.equip(gun);
            map_guns.remove(gun);
            return;
        }
    }
}

bool GameLogic::is_player_out_of_map(Player& player) {
    Rectangle player_space = player.get_rectangle();
    if (player_space.get_x_max() < 0 || player_space.get_y_max() < 0 ||
        player_space.get_x_min() > GAME_WIDTH || player_space.get_y_min() > GAME_HEIGHT) {
        return true;
    }
    return false;
}

void GameLogic::update_players() {
    for (Player& player: players) {

        if (player.is_dead()) {
            continue;
        }

        player.update(physics);

        if (is_player_out_of_map(player)) {
            player.die();
            continue;
        }

        else {
            if (!player.is_jumping()) {
                update_player_gravity(player);
            }
            update_player_equip_collision(player);
        }
    }
}

void GameLogic::update_player_gravity(Player& player) {
    Positionable* touched_floor = get_player_floor_collision(player);
    if (touched_floor) {
        player.adjust_position_to_floor(touched_floor);
        if (player.is_falling()) {
            player.idle();
        }
    } else {
        player.fall(physics);
    }
}

Player& GameLogic::get_player(const uint8_t& _player_id) {
    for (Player& player: players) {
        if (player.get_id() == _player_id) {
            return player;
        }
    }
    throw std::runtime_error("Player con ID no encontrado");
}

void GameLogic::handle_event(uint8_t player_id, ActionCommand event) {
    try {
        Player& player = get_player(player_id);
        uint8_t event_code = static_cast<uint8_t>(event);  // Emitirá un error si es incompatible
        if (player.is_dead()) {
            return;
        }
        std::cout << (int)player_id << " position: " << player.get_coordinate() << std::endl;
        switch (event_code) {
            case ActionCommand::MOVE_RIGHT:
                // chequear que se pueda
                player.run_right(physics);
                break;
            case ActionCommand::MOVE_LEFT:
                // chequear que se pueda
                player.run_left(physics);
                break;
            case ActionCommand::JUMP:
                // chequear se pueda
                player.jump(physics);
                break;
            case ActionCommand::CROUCH:
                // chequear se pueda
                player.crouch(physics);
                break;
            case ActionCommand::SHOOT:
                player.shoot(map_projectiles, ModeShoot::TRIGGER);
                break;
            case ActionCommand::IDLE:
                player.idle();
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error handle event player " << int(player_id) << ": " << e.what()
                  << std::endl;
    }
}


GameLogic::~GameLogic() {}
