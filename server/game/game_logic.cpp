#include "game_logic.h"

#include <iostream>


GameLogic::GameLogic(ListPlayers& _players, Map& _map, ListGuns& _map_guns, ListProjectiles& _map_projectiles):
        players(_players), map(_map), map_guns(_map_guns), map_projectiles(_map_projectiles), physics() {}

bool GameLogic::is_player_floor_collision(Player& player) {
    for (auto& item: this->map) {
        if (this->physics.collision(player.get_rectangle(), item->get_rectangle())) {
            return true;
        }
    }
    return false;
}


void GameLogic::update_player_equip_collision(Player& player) {
    for (auto& gun: map_guns.get_items()) {
        if (this->physics.collision(player.get_rectangle(), gun->get_rectangle())) {

            player.equip(gun);
            log_player_action(player, "take a gun");
            map_guns.remove(gun);
            return;
        }
    }
}


void GameLogic::update_players() {
    for (Player& player: players) {
        player.update();
        update_player_gravity(player);
        update_player_equip_collision(player);
    }
}

void GameLogic::update_player_gravity(Player& player) {
    if (!is_player_floor_collision(player)) {
        physics.falling(player, 1);
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


// void GameLogic::check_collisions() {
//     for (auto& p: this->players) {
//         if ()
//         if (this->in_floor(p)) { // esto se puede cambair por la lista de armas y/o equipabels,
//         deberi funcar
//             p.idle();
//         } else {
//             p.fall();
//         }
//     }
// }

void GameLogic::handle_event(uint8_t player_id, ActionCommand event) {
    try {
        Player& player = get_player(player_id);
        uint8_t event_code = static_cast<uint8_t>(event);  // Emitirá un error si es incompatible

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
                // chequear se pueda
                log_player_action(player, "shoot");
                ListProjectiles gun_projectiles = player.shoot();
                for(auto* projectile: gun_projectiles.get_items()){
                    map_projectiles.transfer_item(projectile, gun_projectiles);
                }
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error handle event player " << int(player_id) << ": " << e.what()
                  << std::endl;
    }
}


GameLogic::~GameLogic() {}
