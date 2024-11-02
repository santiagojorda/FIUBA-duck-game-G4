#include "game_logic.h"

#include <iostream>

GameLogic::GameLogic(ListPlayers& _players) : players(_players) {}

void GameLogic::move_left_player(uint8_t player_id){
    Player player;
    try{
        player = get_player(player_id);
        std::cout << "Player: " << int(player_id) << " moves to the left" << std::endl;
        player.translate_x(-1);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}

Player& GameLogic::get_player(const uint8_t& _player_id){
    for (Player& player : players){
        if(player.get_id() == _player_id){
            return player;
        }
    }
    throw std::runtime_error("Player con ID no encontrado");
}

void GameLogic::move_right_player(uint8_t player_id){
    Player player;
    try{
        player = get_player(player_id);
        std::cout << "Player: " << int(player_id) << " moves to the right" << std::endl;
        player.translate_x(1);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}


GameLogic::~GameLogic() {}