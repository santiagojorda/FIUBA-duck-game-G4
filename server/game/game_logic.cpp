#include "game_logic.h"

#include <iostream>


#include "../events/event_player.h"
#include "../../common/state_duck.h"


GameLogic::GameLogic(ListPlayers& _players, Map& _map, ListGuns& _guns,
                     ListProjectiles& _projectiles):
        players(_players),
        map(_map),
        guns(_guns),
        projectiles(_projectiles),
        physics(map) {}

void GameLogic::update_player_equip_collision(Player& player) {
    for (std::shared_ptr<Gun> gun: guns.get_items()) {
        if (this->physics.collision(player.get_rectangle(), gun->get_rectangle())) {
            player.equip(gun);
            guns.remove(gun);
            return;
        }
    }
}


void GameLogic::update_projectiles(){
    for (std::shared_ptr<Projectile> projectile: projectiles.get_items()){
        if(projectile->is_dead()){
            projectiles.remove(projectile);
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

        if (physics.is_player_out_of_map(player)) {
            player.die();
            continue;
        }

        else {
            if (!player.is_jumping()) {
                physics.update_player_gravity(player);
            }
            update_player_equip_collision(player);
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

void GameLogic::handle_event(const uint8_t& player_id, EventPlayer& event) {
    try {
        Player& player = get_player(player_id);
        if (player.is_dead()) {
            return;
        }
        
        event.execute(player, *this);
    } catch (const std::exception& e) {
        std::cerr << "No existe player de id " << int(player_id) << ": " << e.what()<< std::endl;
    }
}

ListProjectiles& GameLogic::get_projectiles() { return projectiles;}
GamePhysics& GameLogic::get_physics() { return physics;}


GameLogic::~GameLogic() {}
