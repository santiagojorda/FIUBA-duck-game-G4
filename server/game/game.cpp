#include "game.h"

#include <iostream>

#include "../events/event.h"
#include "../weapons/gun_factory.h"
#include "../map/ground.h"
#include "../player/player.h"
#include "../yamel/map_deserialize.h"


#define MAX_ROUNDS_WINDS 10
#define MILISECONDS_30_FPS 33
#define MILISECONDS_FOR_SECONDS 1000
#define SECONDS_FINISH_GAME 3

Game::Game(ListPlayers& _players, MonitorClients& _monitor_client, QueueEvents& _queue_events,
           QueueGameState& _queue_gamestate,
           const std::string& path_map):
        players(_players),
        map(),
        map_items(),
        map_projectiles(),
        game_logic(players, map, map_items, map_projectiles),
        monitor_client(_monitor_client),
        queue_events(_queue_events),
        queue_gamestate(_queue_gamestate),
        round_manager(players){
    this->load_map(path_map);
}



void charge_ponits(ListPlayers& players, std::vector<Coordinate>& points) {
    int i = 0;
    for (Player& player: players) {
        player.set_coordinate(points[i]);
        i++;
        player.reset();
    }
}

void charge_weapons(ListItemsMap& items, std::list<data_weapon>& data_weapons) {
    GunFactory factory;
    for (auto& weapon: data_weapons) {
        std::shared_ptr<Equippable> new_item = factory.create_gun(weapon.id, weapon.coordinate);
        items.add(new_item);
    }
}

void Game::load_map(const std::string& path_map) {
    try {
        MapDeserialize deserialize(path_map);
        std::vector<Coordinate> points;
        std::list<data_weapon> data_weapons;

        deserialize.load_floors(this->map);
        deserialize.load_boxes(this->map);
        deserialize.load_inicial_points(this->inicial_values.points);
        deserialize.load_weapons(this->inicial_values.data_weapons);
        charge_ponits(this->players, this->inicial_values.points);
        charge_weapons(this->map_items, this->inicial_values.data_weapons);
    } catch (const std::exception& e) {
        std::cerr << "error map.yaml: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unespected error map.yaml" << '\n';
    }
}


void Game::reset_values(){
    this->map_items.clear();
    this->map_projectiles.clear();
    charge_ponits(this->players, this->inicial_values.points);
    charge_weapons(this->map_items, this->inicial_values.data_weapons);
}

void Game::execute_new_events() {
    std::shared_ptr<Event> event = nullptr;
    while (queue_events.try_pop(event)) {
        if (event != nullptr) {
            event->start(game_logic);
        }
    }
}

void Game::broadcast_gamestate() { monitor_client.broadcast(get_gamestate()); }

GameState_t Game::get_gamestate() { return GameState_t{this->moment, players, map, map_items, map_projectiles, this->round_manager.get_statistics()}; }

void Game::display_info(SleepSpecial& sleep){
    this->moment = GameMoment::DISPLAY_INFO;
    sleep.sleep(SECONDS_FINISH_GAME * MILISECONDS_FOR_SECONDS);
    this->reset_values();
    this->round_manager.log_state(std::cout, this->get_gamestate());
    sleep.reset();
}


void Game::run() {
    SleepSpecial sleep(MILISECONDS_30_FPS);

    try {
        while (_keep_running && monitor_client.they_are_alive()) {
            this->moment = GameMoment::IN_GAME;
            execute_new_events();
            game_logic.update();
            broadcast_gamestate();
            sleep.sleep_rate();
            if(this->round_manager.check_winer(this->players)) {
                this->display_info(sleep);
            }
            if(this->round_manager.get_rounds_winer() >= MAX_ROUNDS_WINDS) {
                this->moment = GameMoment::FINISHED;
                broadcast_gamestate();
                this->stop();
            }
        }
        stop();
        this->round_manager.log_state(std::cout, this->get_gamestate());
    } catch (std::exception& e) {
        std::cout << "Game: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Hubo un error en el game loop" << std::endl;
        stop();
    }
}

void Game::stop() {
    queue_events.close();
    queue_gamestate.close();
    monitor_client.shutdown();
    Thread::stop();
}

Game::~Game() { Thread::~Thread(); }