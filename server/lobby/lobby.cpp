#include "lobby.h"

#include <iostream>

#include "../client/acceptor_clients.h"

Lobby::Lobby(): monitor_clients(), players_id(), queue_event(), queue_gamestate() {}

void Lobby::accept_clients() {
    AcceptorClients acceptor_clients(monitor_clients, queue_gamestate, queue_event, players_id);
    acceptor_clients.start();
    acceptor_clients.join();
}

void Lobby::init_players() {
    for (uint8_t player_id: players_id) {
        std::cout << "player: " << player_id << " created" << std::endl;
        players.emplace_back(player_id);
    }
}

void Lobby::init_game() {
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