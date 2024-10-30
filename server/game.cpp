#include "game.h"

#include <chrono>

#include "event_player.h"
#include "player.h"


Game::Game(std::list<int>& _players_id, MonitorClients& _monitor_client,
           Queue<Event*>& _queue_event, Queue<GameState_t>& _queue_gamestate):
        monitor_client(_monitor_client),
        queue_event(_queue_event),
        queue_gamestate(_queue_gamestate) {
    for (int player_id: _players_id) {
        players.emplace_back(player_id);
    }
}

void Game::run() {

    try {

        while (_keep_running) {
            Event* event;  // aca hay que ver si usar eventPlayer directo
            while (this->queue_event.try_pop(event)) {
                throw std::exception();
            }


            std::this_thread::sleep_for(std::chrono::milliseconds(33));  // en principio
        }

    } catch (...) {}
}

void Game::stop() {
    queue_event.close();
    queue_gamestate.close();
    monitor_client.shutdown();
    Thread::stop();
}

Game::~Game() { Thread::~Thread(); }