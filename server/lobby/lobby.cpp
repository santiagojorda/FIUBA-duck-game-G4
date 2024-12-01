#include "lobby.h"

#include <iostream>

#include "../client/acceptor_clients.h"
#define PATH_MAP "../game_rsc/maps/map01.yaml"

Lobby::Lobby(): monitor_clients(), players_id(), queue_events(), queue_gamestate() {}

void Lobby::accept_clients() {
    AcceptorClients acceptor_clients(monitor_clients, queue_gamestate, queue_events, players_id);
    acceptor_clients.start();
    acceptor_clients.join();
}

void Lobby::init_players() {
    for (uint8_t player_id: players_id) {
        players.emplace_back(player_id);
    }
}

void Lobby::init_game() {
    init_players();
    Game game(players, monitor_clients, queue_events, queue_gamestate, PATH_MAP);
    game.start();
    game.join();
}

void Lobby::run() {
    accept_clients();
    init_game();
}

Lobby::~Lobby() {}