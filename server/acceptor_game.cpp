#include "acceptor_game.h"

#include <list>

#include "game.h"
#include "lobby.h"
#include "protocol_server.h"

AcceptorGame::AcceptorGame(const std::string& _servname): Acceptor(_servname) {}

void AcceptorGame::listen_new_game() {  // famoso lobby ??
    Socket new_skt = skt.accept();

    ProtocolServer protocol(new_skt);
}

void AcceptorGame::run() {
    try {
        // hay que ver cuantos clientes puede aceptar
        // while(true){ 
        listen_new_game();
        // }
    } catch (...) {}
}

void AcceptorGame::stop() {
    skt.shutdown(2);
    skt.close();
}

AcceptorGame::~AcceptorGame() { Acceptor::~Acceptor(); }
