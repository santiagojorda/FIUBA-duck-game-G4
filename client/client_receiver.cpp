#include "client_receiver.h"

ClientReceiver::ClientReceiver(ClientProtocol& protocol, Queue<std::vector<Coordinate>>& positions):
        protocol(protocol), positions(positions) {}

void ClientReceiver::run() {
    try {
        while (this->is_alive()) {
            std::vector<Coordinate> coordinates = protocol.receiver_players_();
            positions.push(coordinates);
        }
    } catch (const std::exception& e) {
        // protocol lanza la exception: check_is_closed
        this->_is_alive = false;
    }
}

ClientReceiver::~ClientReceiver() { this->join(); }

/*
void ClientReceiver::receiver_data(std::vector<Coordinate>& coordenadas) {
    protocol.receiver_players(coordenadas);
}
*/