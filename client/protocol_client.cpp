#include "protocol_client.h"

ClientProtocol::ClientProtocol(Socket& skt): Protocol(skt) {}


Coordinate ClientProtocol::receive_cordinates() {
    uint16_t x;
    this->receive_2_bytes(x);
    uint16_t y;
    this->receive_2_bytes(y);
    uint16_t h;
    this->receive_2_bytes(h);
    uint16_t w;
    this->receive_2_bytes(w);
    return Coordinate(x, y, h, w);
}

void ClientProtocol::send_action(int& id_jugador, uint8_t& type_action) {  // pasarle action
    std::vector<uint8_t> vector_data;
    vector_data.push_back(HEADER_CLIENT);  // 1 byte
    vector_data.push_back(id_jugador);     // 1 byte
    vector_data.push_back(type_action);    // 1 byte
    this->skt.sendall(vector_data.data(), vector_data.size(), &this->was_closed);
}

std::vector<Coordinate> ClientProtocol::receiver_players_() {
    uint8_t cantidad_players;
    this->receive_byte(cantidad_players);

    std::vector<Coordinate> coordenadas; // mapa  -> clave: id jugador , valor : position
    // guardar vector las coordenadas
    for (size_t i = 0; i < cantidad_players; i++) {
        uint8_t id_player;
        this->receive_byte(id_player);
        
        Coordinate coordinate = this->receive_cordinates();
        coordenadas.push_back(coordinate);
    }

    // uint8_t camara;
    // this->receive_byte(camara);
    return coordenadas;
}

void ClientProtocol::send_init(const uint8_t& init) {
    // envia cantidad de jugadores
    this->send_byte(init);
}
