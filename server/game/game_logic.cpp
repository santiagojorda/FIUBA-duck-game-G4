#include "game_logic.h"

#include <iostream>

#include "../../common/state_duck.h"

#define GAME_WIDTH 800
#define GAME_HEIGHT 500
#define IS_TOUCHING_FLOOR true

GameLogic::GameLogic(ListPlayers& _players, Map& _map, ListGuns& _map_guns,
                     ListProjectiles& _map_projectiles):
        players(std::move(_players)),
        map(_map),
        map_guns(_map_guns),
        map_projectiles(_map_projectiles),
        physics(map) {}

std::shared_ptr<Positionable> GameLogic::get_player_floor_collision(Player& player) {
    for (auto& tile: this->map) {
        if (this->physics.collision(player.get_rectangle(), tile->get_rectangle())) {
            player.set_touching_floor(IS_TOUCHING_FLOOR);
            return tile;
        }
    }
    return nullptr;
}

void GameLogic::update_player_equip_collision(Player& player) {
    for (std::shared_ptr<Gun> gun: map_guns.get_items()) {
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




void GameLogic::update_projectiles(){
    for (std::shared_ptr<Projectile> projectile: map_projectiles.get_items()){
        if(projectile->is_dead()){
            map_projectiles.remove(projectile);
            return;
        }
        projectile->update(physics);

    }

    
}


void GameLogic::update(){

    update_projectiles();
    update_players();

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
    std::shared_ptr<Positionable> touched_floor = get_player_floor_collision(player);
    if (touched_floor) {
        player.adjust_position_to_floor(touched_floor);
        if (player.is_falling()) {
            player.idle();
        }
    } else {
        player.fall(physics);
        player.set_touching_floor(!IS_TOUCHING_FLOOR);
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

void GameLogic::handle_event(const uint8_t& player_id, const ActionEvent& event) {
    try {
        Player& player = get_player(player_id);
        if (player.is_dead()) {
            return;
        }
        switch (event) {
            case ActionEvent::MOVE_RIGHT:
                // chequear que se pueda
                player.run_right(physics);
                break;
            case ActionEvent::MOVE_LEFT:
                // chequear que se pueda
                player.run_left(physics);
                break;
            case ActionEvent::JUMP:
                // chequear se pueda
                player.jump(physics);
                break;
            case ActionEvent::CROUCH:
                // chequear se pueda
                player.crouch(physics);
                break;
            case ActionEvent::TRIGGER:
                player.shoot(map_projectiles, ModeShoot::TRIGGER);
                break;
            case ActionEvent::TRIGGER_OUT:
                player.shoot(map_projectiles, ModeShoot::TRIGGER_OUT);
                break;
            case ActionEvent::IDLE:
                player.idle();
                break;
            default:
                break;  
        }
    } catch (const std::exception& e) {
        std::cerr << "No existe player de id " << int(player_id) << ": " << e.what()
                  << std::endl;
    }
}


GameLogic::~GameLogic() {}
