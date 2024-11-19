#include "client.h"

#include <iostream>

enum N_players { ONE_PLAYER = 1, TWO_PLAYER, MAX_PLAYER = 2 };

// agregar queue
Client::Client(const std::string& _hostname, const std::string& _servname):
        hostname(_hostname),
        servname(_servname),
        skt(_hostname.c_str(), _servname.c_str()),
        protocol(skt),
        commands(),
        game_state(),
        receiver(protocol, game_state),
        sender(protocol, commands),
        drawer(commands, game_state) {

    this->protocol.send_init(ONE_PLAYER);
}

Client::Client(const std::string& _hostname, const std::string& _servname, int N_players):
        hostname(_hostname),
        servname(_servname),
        skt(_hostname.c_str(), _servname.c_str()),
        protocol(skt),
        commands(),
        game_state(),
        receiver(protocol, game_state),
        sender(protocol, commands),
        drawer(commands, game_state) {

    this->protocol.send_init(N_players > MAX_PLAYER ? MAX_PLAYER : N_players);
}

void Client::run() {
    receiver.start();
    sender.start();

    drawer.run();

    this->skt.shutdown(2);
    this->commands.close();
}

void Client::generate_conection() {
    Socket skt(this->hostname.c_str(), this->servname.c_str());
    ClientProtocol protocol(skt);
    protocol.send_init(0xFF);
}

Client::~Client(){
    receiver.stop();
    sender.stop();

    receiver.join();
    sender.join();
}
