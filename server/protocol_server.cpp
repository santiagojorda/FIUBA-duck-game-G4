#include "protocol_server.h"


ProtocolServer::ProtocolServer(Socket& skt): Protocol(std::move(skt)) {}


void ProtocolServer::send_game_estate(const GameState_t& estate) {
    this->send_byte(estate.N_players);
}