#include "game.h"

#include <chrono>
#include <iostream>

#include "event_player.h"
#include "player.h"

#define MILISECONDS_30_FPS 33


Game::Game(ListPlayers& _players, MonitorClients& _monitor_client, QueueEventPlayer& _queue_event,
           QueueGameState& _queue_gamestate):
        players(_players),
        game_logic(players),
        monitor_client(_monitor_client),
        queue_event(_queue_event),
        queue_gamestate(_queue_gamestate) {}

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
    GameState_t game_state;

    game_state.N_players = players.size();
    game_state.players = players;
    return game_state;
}

auto Game::get_actual_milliseconds() { return std::chrono::high_resolution_clock::now(); }

void Game::run() {

    auto chrono_now = get_actual_milliseconds();
    auto chrono_prev = chrono_now;

    try {

        while (_keep_running) {
            execute_new_events();
            // *(2) o podria procesar todos los mensajes en la cola y luego enviar un gamestate como
            // broadcast_gamestate
            game_logic.apply_gravity();
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