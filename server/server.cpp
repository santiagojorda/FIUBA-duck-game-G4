#include "server.h"

#include "lobby.h"

Server::Server() {}

void Server::run() {

    // el servidor deberia buscar un slot libre??
    // char servname[] = "8081";

    // MonitorGame monitor_games;

    // AcceptorGame acceptor_game(servname, monitor_games);
    // acceptor_game.run();
    
    Lobby lobby;

    // acceptor_game.join();

    // acceptor_game.stop();
}
