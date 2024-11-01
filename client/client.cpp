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
    this->protocol.send_init(2);
    

    // esto hay que refactorizar
    // cliente 0: evento
    protocol.send_init(0xA);
    protocol.send_init(0);
    protocol.send_init(0);


    // cliente 1: evento
    protocol.send_init(0xA);
    protocol.send_init(1);
    protocol.send_init(1);
}

/**
Client::Client(const std::string& hostname, const std::string& servname, int N_players):
        hostname(hostname),
        servicename(servname),
        //skt(hostname.c_str(), servname.c_str()),
        //protocol(skt),
        drawer() {
    //this->protocol.send_init(N_players > MAX_PLAYER ? MAX_PLAYER : N_players);
}
 */
void Client::run() { drawer.run(); }
