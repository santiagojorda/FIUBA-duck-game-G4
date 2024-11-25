#include "game.h"

#include <iostream>

#include "../../common/sleep_special.h"
#include "../events/event_player.h"
#include "../weapons/gun_factory.h"
#include "../map/ground.h"
#include "../player/player.h"
#include "../yamel/map_deserialize.h"

#define PATH_MAP "../game_rsc/maps/map01.yaml"

#define MILISECONDS_30_FPS 33

void charge_ponits(ListPlayers& players, std::vector<Coordinate>& points) {
    int i = 0;
    for (Player& player: players) {
        player.set_coordinate(points[i]);
        i++;
        std::cout << player.get_coordinate() << std::endl;
    }
}

void charge_weapons(ListGuns& guns, std::list<data_weapon>& data_weapons) {
    GunFactory factory;
    for (auto& weapon: data_weapons) {
        guns.add(factory.create_gun(weapon.id, weapon.coordinate));
    }
}

void Game::load_map() {
    try {
        MapDeserialize deserialize(PATH_MAP);
        std::vector<Coordinate> points;
        std::list<data_weapon> data_weapons;

        deserialize.load_floors(this->map);
        deserialize.load_inicial_points(points);
        deserialize.load_weapons(data_weapons);
        charge_ponits(this->players, points);
        charge_weapons(this->map_guns, data_weapons);
    } catch (const std::exception& e) {
        std::cerr << "error map.yaml: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unespected error map.yaml" << '\n';
    }
}


Game::Game(ListPlayers& _players, MonitorClients& _monitor_client, QueueEventPlayer& _queue_event,
           QueueGameState& _queue_gamestate):
        players(_players),
        map(),
        map_guns(),
        map_projectiles(),
        game_logic(players, map, map_guns, map_projectiles),
        monitor_client(_monitor_client),
        queue_event(_queue_event),
        queue_gamestate(_queue_gamestate) {
    this->load_map();
}

void Game::execute_new_events() {
    std::shared_ptr<EventPlayer> event = nullptr;
    while (queue_event.try_pop(event)) {
        if (event != nullptr) {
            event->execute(game_logic);
        }
        // delete event;
        event = nullptr;
    }
}

void Game::broadcast_gamestate() { monitor_client.broadcast(get_gamestate()); }

GameState_t Game::get_gamestate() { return GameState_t{players, map, map_guns, map_projectiles}; }

void Game::run() {
    SleepSpecial sleep(MILISECONDS_30_FPS);
    try {

        while (_keep_running && monitor_client.they_are_alive()) {
            execute_new_events();
            game_logic.update();
            broadcast_gamestate();
            sleep.sleep_rate();
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
    queue_event.close();
    queue_gamestate.close();
    monitor_client.shutdown();
    Thread::stop();
}

Game::~Game() { Thread::~Thread(); }