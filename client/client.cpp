#include "client.h"

#include <iostream>
#include <sstream>

enum N_players { ONE_PLAYER = 1, TWO_PLAYER, MAX_PLAYER = 2 };

// agregar queue
Client::Client(const std::string& hostname, const std::string& servname):
        skt(hostname.c_str(), servname.c_str()),
        protocol(skt),
        commands(),
        positions(),
        receiver(protocol, positions),
        sender(protocol, commands),
        drawer(commands, positions) {

    this->protocol.send_init(ONE_PLAYER);
}

/*
Client::Client(const std::string& hostname, const std::string& servname, int N_players):
        hostname(hostname),
        servicename(servname),
        skt(hostname.c_str(), servname.c_str()),
        protocol(skt),
        drawer() {
    this->protocol.send_init(N_players > MAX_PLAYER ? MAX_PLAYER : N_players);
}*/


void Client::run() {
    // recibo posiciones iniciales
    // std::vector<Coordinate> coordenadas;
    // receiver.receiver_players(coordenadas);

    // while (true) // despues cambiarlo
    //{

    // Starteo los receiver y sender
    receiver.start();
    sender.start();
    drawer.run();
}
