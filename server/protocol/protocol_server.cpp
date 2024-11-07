#include "protocol_server.h"

#define BYTE_CLIENT 0xA

ProtocolServer::ProtocolServer(Socket& skt): Protocol(skt) {}

void ProtocolServer::send_cordinates(const Coordinate& send) {
    this->send_2_bytes(send.get_x());
    this->send_2_bytes(send.get_y());
    this->send_2_bytes(send.get_h());
    this->send_2_bytes(send.get_w());
}

void ProtocolServer::send_game_state(const GameState_t& state) {
    this->send_byte(state.N_players);

    for (const Player& player: state.players) {
        this->send_byte(player.get_id());
        this->send_cordinates(player.get_coordinate());
    }
}

uint8_t ProtocolServer::receive_count_players() {
    uint8_t count_players = 0;
    receive_byte(count_players);
    return count_players;
}

void ProtocolServer::receive_event(uint8_t& player_id, uint8_t& event_id) {
    uint8_t code_client = 0;
    this->receive_byte(code_client);
    if (code_client == BYTE_CLIENT) {
        this->receive_byte(player_id);
        this->receive_byte(event_id);
    }
}


ProtocolServer::~ProtocolServer() {}