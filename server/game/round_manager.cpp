#include "round_manager.h"



RoundManager::RoundManager(const ListPlayers& players) {
    for (const auto& player: players) {
        this->statistics.count_winer[player.get_texture_id()] = 0;
    }
}

bool RoundManager::check_winer(const ListPlayers& players){
    int lives = players.size();
    uint8_t id_winer = 0xFF;
    for (const auto& player: players) {
        if(player.is_dead()){
            lives--;
        }  else {
            id_winer = player.get_texture_id();
        }
    }
    if(lives <= 1){
        this->statistics.rounds++;
        this->statistics.count_winer[id_winer] ++;
        return true;
    }
    return false;
}



void RoundManager::log_state(std::ostream& log, const GameState_t& state){

    log << std::endl  << "+====================================+:" << std::endl;

    log << "Players:" << std::endl;
    for (const auto& player : state.players) {
    log << "  - Player ID: " << (int)  player.get_texture_id()  << " Cordinate:"<< player.get_coordinate() << std::endl;
    log << " - Round wining: " <<  this->statistics.count_winer[player.get_texture_id()]  << std::endl;

    }

    log << "Map Items:" << std::endl;
    for (const auto& item : state.map_items.get_items()) {
        log << "  - Item ID: " << (int) item->get_texture_id() << " Cordinate:"<< item->get_coordinate()  << std::endl;
    }

    log << "Map Projectiles:" << std::endl;
    for (const auto& projectile : state.map_projectiles.get_items()) {
        log << "  - Projectile ID: " << (int) projectile->get_texture_id() << " Cordinate:"<< projectile->get_coordinate() << std::endl;
    }
    
    log << std::endl  << "+====================================+:" << std::endl;
}


RoundManager::~RoundManager() {}


