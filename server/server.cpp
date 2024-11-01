#include "server.h"

#include <iostream>

#include "lobby.h"

Server::Server() = default;

void Server::run() {

    // el servidor deberia buscar un slot libre??
    // char servname[] = "8081";

    // MonitorGame monitor_games;

    // AcceptorGame acceptor_game(servname, monitor_games);
    // acceptor_game.run();
    std::cout << "Iniciando server" << std::endl;
    Lobby lobby;
    lobby.run();

    // acceptor_game.join();

    // acceptor_game.stop();
}

Server::~Server() = default;
