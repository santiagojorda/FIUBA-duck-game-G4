#include "game.h"

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

        // while(_keep_running){

        // }

    } catch (...) {}
}

void Game::stop() {
    queue_event.close();
    queue_gamestate.close();
    monitor_client.shutdown();
    Thread::stop();
}

Game::~Game() { Thread::~Thread(); }