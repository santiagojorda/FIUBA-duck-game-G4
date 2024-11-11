#include "game_logic.h"

#include <iostream>

GameLogic::GameLogic(ListPlayers& _players, Map& _map): players(_players), map(_map), physics() {}

void GameLogic::apply_gravity() {

    for (Player& player: players) {
        Coordinate coordinates = player.get_coordinate();
        if (coordinates.get_y() < 200) {  // piso
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

void GameLogic::log_player_action(Player& player, const std::string& action){
    std::cout << "Player " << int(player.get_id()) << " " << action << std::endl;
}

void GameLogic::handle_event(uint8_t player_id, ActionCommand event){
    try{
        Player& player = get_player(player_id);
        uint8_t event_code = static_cast<uint8_t>(event); // Emitirá un error si es incompatible

        switch(event_code){
            case ActionCommand::MOVE_RIGHT:
                // chequear que se pueda
                log_player_action(player, "moves to the right");        
                player.run_right();
                break;
            case ActionCommand::MOVE_LEFT:
                //chequear que se pueda
                log_player_action(player, "moves to the left");    
                player.run_left();
                break;
            case ActionCommand::JUMP:
                //chequear se pueda
                log_player_action(player, "jumps");  
                player.jump();
                break;
            case ActionCommand::CROUCH:
                //chequear se pueda
                log_player_action(player, "crouch");   
                player.crouch();
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error handle event player " << int(player_id) << ": " << e.what() << std::endl;
    }
}


GameLogic::~GameLogic() {}
