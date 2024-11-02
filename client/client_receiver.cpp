#include "client_receiver.h"

ClientReceiver::ClientReceiver(ClientProtocol& protocol,
                               Queue<std::vector<PlayerPosition_t>>& positions):
        protocol(protocol), positions(positions) {}

void ClientReceiver::run() {
    try {
        while (this->is_alive()) {
            std::vector<PlayerPosition_t> coordinates = protocol.receiver_players_();
            positions.push(coordinates);
        }
    } catch (const std::exception& e) {
        // protocol lanza la exception: check_is_closed
        this->_is_alive = false;
    }
}

ClientReceiver::~ClientReceiver() {
    if (this->is_alive()) {
        this->join();
    }
}

/*
void ClientReceiver::receiver_data(std::vector<Coordinate>& coordenadas) {
    protocol.receiver_players(coordenadas);
}
*/