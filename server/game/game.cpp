#include "game.h"

#include <chrono>
#include <iostream>

#include "../events/event_player.h"
#include "../guns/pew_pew_laser.h"
#include "../map/ground.h"
#include "../player/player.h"

#include "../yamel/map_deserialize.h"

#define MILISECONDS_30_FPS 33

void charge_grounds(Map & map, std::list<Coordinate>& floors){
    for(Coordinate& c : floors ){
        map.add(new Ground(c));
    }
}

void Game::load_map(){
    try
    {
        MapDeserialize deserialize("../game_rsc/maps/map01.yaml");
        std::list<Coordinate> floors;
        deserialize.load_floors(floors);
        charge_grounds(this->map, floors);
        //      deserialize.load_inicial_points();
        //        deserialize.load_weapons();
    } catch (const std::exception& e) {
        std::cerr << "error map.yaml" <<e.what() << '\n';
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
    Gun* pew = new PewPewLaser(Coordinate(0, 200, 32, 32));
    map_guns.add(pew);
}

void Game::sleep() { std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS)); }

void Game::execute_new_events() {
    EventPlayer* event = nullptr;
    while (queue_event.try_pop(event)) {
        if (event != nullptr) {
            event->execute(game_logic);  // *(1) creo que deberia devolver un gamestate
        }
        // delete event; // ver logica de events
        event = nullptr;
    }
}

void Game::broadcast_gamestate() { monitor_client.broadcast(get_gamestate()); }

GameState_t Game::get_gamestate() {
    return GameState_t{players, map, map_guns, map_projectiles};
}

auto get_actual_milliseconds() { return std::chrono::high_resolution_clock::now(); }

void Game::run() {

    auto chrono_now = get_actual_milliseconds();
    auto chrono_prev = chrono_now;

    try {

        while (_keep_running) {
            game_logic.update_players();
            execute_new_events();
            // *(2) o podria procesar todos los mensajes en la cola y luego enviar un gamestate como
            // broadcast_gamestate
            broadcast_gamestate();

            chrono_now = get_actual_milliseconds();
            auto delta_chrono = chrono_now - chrono_prev;
            if (delta_chrono < std::chrono::milliseconds(MILISECONDS_30_FPS)) {
                sleep();
            }
            chrono_prev = get_actual_milliseconds();
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