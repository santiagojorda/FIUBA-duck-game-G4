#include "game_logic.h"

#include <iostream>

GameLogic::GameLogic(ListPlayers& _players, Map& _map): 
    players(_players), 
    map(_map),
    physics()
    {}

void GameLogic::apply_gravity() {

    for (Player& player: players) {
        Coordinate coordinates = player.get_coordinate();
        if (coordinates.get_y() < 200) {  // piso
            physics.falling(player, 1);
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

void GameLogic::move_left_player(uint8_t player_id) {
    try {
        Player& player = get_player(player_id);
        std::cout << "Player: " << int(player.get_id()) << " moves to the left" << std::endl;
        player.translate_x(-5);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void GameLogic::move_right_player(uint8_t player_id) {
    try {
        Player& player = get_player(player_id);
        std::cout << "Player: " << int(player.get_id()) << " moves to the right" << std::endl;
        player.translate_x(5);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void GameLogic::crouch_player(uint8_t player_id) {
    try {
        Player& player = get_player(player_id);
        std::cout << "Player: " << int(player.get_id()) << " crouchs" << std::endl;
        player.translate_y(1);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}


void GameLogic::jump_player(uint8_t player_id) {
    try {
        Player& player = get_player(player_id);
        std::cout << "Player: " << int(player.get_id()) << " jumps" << std::endl;
        player.translate_y(-10);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

GameLogic::~GameLogic() {}
