#include "lobby.h"

#include "acceptor_clients.h"

#include <iostream>

#define MAX_EVENTS_QUEUE 100

Lobby::Lobby():
        monitor_clients(),
        players_id(),
        queue_event(MAX_EVENTS_QUEUE),
        queue_gamestate() {}

void Lobby::accept_clients(){
    AcceptorClients acceptor_clients(monitor_clients, queue_gamestate, queue_event, players_id);
    acceptor_clients.start();
    acceptor_clients.join();
}

void Lobby::init_players(){
    for (uint8_t player_id: players_id) {
        std::cout << "player: " << player_id << " created" << std::endl;
        players.emplace_back(player_id);
    }
}

void Lobby::init_game(){
    init_players();
    Game game(players, monitor_clients, queue_event, queue_gamestate);
    game.start();
    game.join();  
}

void Lobby::run() {
    accept_clients();
    init_game();
}

Lobby::~Lobby() {}