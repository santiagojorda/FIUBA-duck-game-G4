#include "game_logic.h"

#include <iostream>
#include "../../common/state_duck.h"


GameLogic::GameLogic(ListPlayers& _players, Map& _map, ListGuns& _map_guns,
                     ListProjectiles& _map_projectiles):
        players(_players),
        map(_map),
        map_guns(_map_guns),
        map_projectiles(_map_projectiles),
        physics() {}

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


void GameLogic::update_players() {
    for (Player& player: players) {
        player.update();
        if(!player.is_jumping()){
            update_player_gravity(player);
        }
        update_player_equip_collision(player);
    }
}

void GameLogic::update_player_gravity(Player& player) {
    Positionable* touched_floor = get_player_floor_collision(player); 
    if (touched_floor) {
        // player.touch_floor(touched_floor);
        // si es que no baja mas, que acomode el sobrante
        player.adjust_position_to_floor(touched_floor);
    }
    else {
        player.fall(physics);
        // physics.falling(player, player.get_frame());
        
        // player.fall();
        // physics.falling(player, 1);
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

void GameLogic::log_player_action(Player& player, const std::string& action) {
    std::cout << "Player " << int(player.get_id()) << " " << action << std::endl;
}

void GameLogic::handle_event(uint8_t player_id, ActionCommand event) {
    try {
        Player& player = get_player(player_id);
        uint8_t event_code = static_cast<uint8_t>(event);  // Emitirá un error si es incompatible

        std::cout << (int)player_id << " position: " << player.get_coordinate() << std::endl;
        switch (event_code) {
            case ActionCommand::MOVE_RIGHT:
                // chequear que se pueda
                log_player_action(player, "moves to the right");
                player.run_right();
                break;
            case ActionCommand::MOVE_LEFT:
                // chequear que se pueda
                log_player_action(player, "moves to the left");
                player.run_left();
                break;
            case ActionCommand::JUMP:
                // chequear se pueda
                log_player_action(player, "jumps");
                player.jump();
                break;
            case ActionCommand::CROUCH:
                // chequear se pueda
                log_player_action(player, "crouch");
                player.crouch();
                break;
            case ActionCommand::SHOOT:
                log_player_action(player, "shoot");
                player.shoot(map_projectiles);
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error handle event player " << int(player_id) << ": " << e.what()
                  << std::endl;
    }
}


GameLogic::~GameLogic() {}
