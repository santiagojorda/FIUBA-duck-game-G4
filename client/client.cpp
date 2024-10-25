#include "client.h"

#include <iostream>
#include <sstream>

enum N_players { ONE_PLAYER = 1, TWO_PLAYER, MAX_PLAYER = 2 };

Client::Client(const std::string& hostname, const std::string& servname):
        hostname(hostname),
        servicename(servname),
        skt(hostname.c_str(), servname.c_str()),
        protocol(skt),
        drawer() {
    this->protocol.send_init(ONE_PLAYER);
}

Client::Client(const std::string& hostname, const std::string& servname, int N_players):
        hostname(hostname),
        servicename(servname),
        skt(hostname.c_str(), servname.c_str()),
        protocol(skt),
        drawer() {
    this->protocol.send_init(N_players > MAX_PLAYER ? MAX_PLAYER : N_players);
}


void Client::run() { drawer.run(); }
