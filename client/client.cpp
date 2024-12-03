#include "client.h"

#include <iostream>
#include <sstream>

enum N_players { ONE_PLAYER = 1, TWO_PLAYER, MAX_PLAYER = 2 };

// agregar queue
Client::Client(const std::string& hostname, const std::string& servname):
        skt(hostname.c_str(), servname.c_str()),
        protocol(skt),
        commands(),
        game_state(),
        receiver(protocol, game_state),
        sender(protocol, commands),
        drawer(commands, game_state) {

    this->protocol.send_init(TWO_PLAYER);
}


Client::Client(const std::string& hostname, const std::string& servname, int N_players):
        skt(hostname.c_str(), servname.c_str()),
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

    // drawer termino
    this->skt.shutdown(2);
    this->commands.close();
}

Client::~Client(){
    receiver.stop();
    sender.stop();

    receiver.join();
    sender.join();

}

