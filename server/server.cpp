#include "server.h"

#include <iostream>

#include "lobby.h"

Server::Server() = default;

void Server::run() {

    std::cout << "Iniciando server" << std::endl;
    Lobby lobby;
    lobby.run();
}

Server::~Server() = default;
