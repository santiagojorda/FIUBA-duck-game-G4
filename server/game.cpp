#include "game.h"

#include <chrono>

#include "event_player.h"
#include "player.h"

#define MILISECONDS_30_FPS 33


Game::Game(std::list<int>& _players_id, MonitorClients& _monitor_client,
           Queue<Event*>& _queue_event, Queue<GameState_t>& _queue_gamestate):
        game_logic(players),
        monitor_client(_monitor_client),
        queue_event(_queue_event),
        queue_gamestate(_queue_gamestate) {
    for (int player_id: _players_id) {
        players.emplace_back(player_id);
    }
}

void Game::sleep(){
    std::this_thread::sleep_for(std::chrono::milliseconds(MILISECONDS_30_FPS));
}

void Game::execute_new_events(){
    Event* event = nullptr;
    while (queue_event.try_pop(event)){
        if (event != nullptr){
            event->execute(game_logic); // *(1) creo que deberia devolver un gamestate
        }
        delete event;
        // event = nullptr;
    }
}

void Game::broadcast_gamestate(){
    monitor_client.broadcast(get_gamestate());
}

GameState_t Game::get_gamestate(){
    GameState_t game_state;

    game_state.N_players = players.size(); 
    game_state.players = players;
    return game_state;
}

void Game::run() {

    try {

        while (_keep_running) {
            execute_new_events();
            // *(2) o podria procesar todos los mensajes en la cola y luego enviar un gamestate como broadcast_gamestate
            broadcast_gamestate();
            sleep();
        }
        stop();

    } catch (...) {
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