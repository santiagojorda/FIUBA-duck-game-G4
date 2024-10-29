#include "protocol_server.h"

ProtocolServer::ProtocolServer(Socket& skt): Protocol(skt) {}

void ProtocolServer::send_cordinates(const Coordinate& send) {
    this->send_2_bytes(send.get_x());
    this->send_2_bytes(send.get_y());
    this->send_2_bytes(send.get_h());
    this->send_2_bytes(send.get_w());
}

void ProtocolServer::send_game_estate(const GameState_t& estate) {
    this->send_byte(estate.N_players);
    for (uint8_t i = 0; i < estate.N_players; i++) {
        this->send_byte(estate.players[i].get_id());
        this->send_cordinates(estate.players[i].get_coordinate());
    }
}

uint8_t ProtocolServer::receive_count_players() {
    uint8_t count_players = 0;
    receive_byte(count_players);
    return count_players;
}