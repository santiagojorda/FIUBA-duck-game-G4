#include "game_logic.h"

#include <iostream>

#include "list_items_map.h"
#include "../events/event.h"
#include "../../common/state_duck.h"
#include "../player/list_players.h"
#include "../weapons/list_projectiles.h"
#include "../weapons/projectiles/bullet.h"

#define DROP_DISTANCE 40

GameLogic::GameLogic(ListPlayers& _players, Map& _map, ListItemsMap& _items,
                     ListProjectiles& _projectiles):
        players(_players),
        map(_map),
        items(_items),
        projectiles(_projectiles),
        physics(map) {}

void GameLogic::update_player_equip_collision(Player& player) {
    // deberiamos chequear equipables
    for (std::shared_ptr<Equippable> item: items.get_items()) {
        if (this->physics.exist_collision(player.get_rectangle(), item->get_rectangle())) {
            player.equip(item);
            if(player.has_equipped_this(item)){
                items.remove(item);
            }
            return;
        }
    }
}

void GameLogic::handle_drop(std::shared_ptr<Equippable> item){
    items.add(item);
    item->translate_x(DROP_DISTANCE);
}

void GameLogic::update_player_gravity(Player& player) {
    std::shared_ptr<Positionable> touched_floor = physics.get_player_floor_collision(player);
    if (touched_floor) {
        player.adjust_position_to_floor(touched_floor);
        if (player.is_falling()) {
            player.idle();
        }
        player.touch_floor();
    } else {
        player.fall(*this);
        // player.set_touching_floor(!IS_TOUCHING_FLOOR);a
    }
}


void GameLogic::update_projectiles(){
    for (std::shared_ptr<Projectile> projectile: projectiles.get_items()){
        if(projectile->is_dead()){
            projectiles.remove(projectile);
            return;
        }
        projectile->update(*this);
    }
}

void GameLogic::remove_bullet(Bullet& bullet){
    projectiles.remove(std::make_shared<Bullet>(bullet));
}

void GameLogic::move(Bullet& bullet, int x, int y){
    for(Player& player : players){
        if(player.is_dead() || player.get_id() == bullet.get_shooter_id()){
            continue;
        }
        if (physics.exist_collision(player.get_rectangle(), bullet.get_rectangle())){
            bullet.handle_collision(player, *this);
            remove_bullet(bullet);
            return;
        }
    }
    
    bullet.translate_x(x);
    bullet.translate_y(y);
}


void GameLogic::update(){

    update_projectiles();
    update_players();

}

void GameLogic::update_players() {
    for (Player& player: players) {

        if (player.is_dead()) {
            player.update(*this);
            continue;
        }


        if (physics.is_player_out_of_map(player)) {
            player.die(*this);
            continue;
        }

        else {
            player.update(*this);
            if (!player.is_jumping()) {
                update_player_gravity(player);
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

void GameLogic::handle_event(Event& event) { event.execute(*this);}

ListProjectiles& GameLogic::get_projectiles() { return projectiles;}
GamePhysics& GameLogic::get_physics() { return physics;}


GameLogic::~GameLogic() {}
