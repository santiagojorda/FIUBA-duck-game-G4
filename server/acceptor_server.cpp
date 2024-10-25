#include "acceptor_server.h"

#include "monitor_games.h"

AcceptorServer::AcceptorServer(const std::string& servname): skt(servname.c_str()) {}

void AcceptorServer::listen_new_server() {
    Socket skt_new_game = skt.accept();
    // Game* new_game = new Game();
    // game_list.push_back(new_game);
}

void AcceptorServer::run() {
    try {
        while (_keep_running) {
            listen_new_server();
        }
    } catch (...) {
        stop();
    }
}

void AcceptorServer::stop() {
    if (_keep_running) {
        Thread::stop();
        skt.shutdown(2);
        skt.close();
    }
}