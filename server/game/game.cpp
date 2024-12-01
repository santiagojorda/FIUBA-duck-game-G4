#include "game.h"

#include <iostream>

#include "../../common/sleep_special.h"
#include "../events/event.h"
#include "../weapons/gun_factory.h"
#include "../map/ground.h"
#include "../player/player.h"
#include "../yamel/map_deserialize.h"

#include "round_manager.h"

#define PATH_MAP "../game_rsc/maps/map01.yaml"

#define MILISECONDS_30_FPS 33
#define MILISECONDS_FOR_SECONDS 1000
#define SECONDS_FINISH_GAME 4

Game::Game(ListPlayers& _players, MonitorClients& _monitor_client, QueueEvents& _queue_events,
           QueueGameState& _queue_gamestate):
        players(_players),
        map(),
        map_projectiles(),
        game_logic(players, map, map_projectiles),
        monitor_client(_monitor_client),
        queue_events(_queue_events),
        queue_gamestate(_queue_gamestate){
    this->load_map();
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

void Game::load_map() {
    try {
        MapDeserialize deserialize(PATH_MAP);
        std::vector<Coordinate> points;
        std::list<data_weapon> data_weapons;

        deserialize.load_floors(this->map);
        deserialize.load_boxes(this->map);
        deserialize.load_inicial_points(this->inicial_values.points);
        deserialize.load_weapons(this->inicial_values.data_weapons);
        charge_ponits(this->players, this->inicial_values.points);
        // charge_weapons(this->map_items, this->inicial_values.data_weapons);
    } catch (const std::exception& e) {
        std::cerr << "error map.yaml: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unespected error map.yaml" << '\n';
    }
}


void Game::reset_values(){
    // this->map_items.clear();
    charge_ponits(this->players, this->inicial_values.points);
    // charge_weapons(this->map_items, this->inicial_values.data_weapons);
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

GameState_t Game::get_gamestate() { return GameState_t{players, map, map_projectiles}; }

void Game::run() {
    SleepSpecial sleep(MILISECONDS_30_FPS);
    RoundManager round_manager(this->players);
    CircularCounter log_counter(33);

    try {

        while (_keep_running && monitor_client.they_are_alive()) {
            execute_new_events();
            game_logic.update();
            broadcast_gamestate();
            sleep.sleep_rate();
            if(round_manager.check_winer(this->players)) {
                sleep.sleep(SECONDS_FINISH_GAME * MILISECONDS_FOR_SECONDS);
                this->reset_values();
                sleep.reset();
                // sleep = SleepSpecial(MILISECONDS_30_FPS);
            }
            if(log_counter()) round_manager.log_state(std::cout, this->get_gamestate());

        }
        stop();
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