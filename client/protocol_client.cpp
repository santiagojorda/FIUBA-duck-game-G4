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


void ClientProtocol::send_init(const uint8_t& init) { this->send_byte(init); }
