#include "game_logic.h"

#include <iostream>


GameLogic::GameLogic(ListPlayers& _players, Map& _map): players(_players), map(_map), physics() {}

bool GameLogic::in_floor(const Player& player){
    bool in_floor = false;
    for (auto& tile: this->map) {
        if(this->physics.collision(player.get_rectangle(), tile->get_rectangle())){
            std::cout << "floor is: "<< in_floor << std::endl;
            in_floor = true;
        }
    }
    return in_floor;
}

void GameLogic::apply_gravity() {
    for (Player& player: players) {
        Coordinate coordinates = player.get_coordinate();
        if (!this->in_floor(player)) {  // piso
            physics.falling(player, 1);
            log_player_action(player, "falls");
        }
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


void GameLogic::slove_collision() {
    for (auto& p: this->players) {
        if (this->in_floor(p)) { // esto se puede cambair por la lista de armas y/o equipabels, deberi funcar 
            p.idle();
        } else {
            p.fall();
        }
    }
}

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
        }
    } catch (const std::exception& e) {
        std::cerr << "Error handle event player " << int(player_id) << ": " << e.what()
                  << std::endl;
    }
}


GameLogic::~GameLogic() {}
