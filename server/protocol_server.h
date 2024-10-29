#ifndef SERVER_PROTOCOL_SERVER_H_
#define SERVER_PROTOCOL_SERVER_H_

#include <cstdint>
#include <string>

#include "../common/protocol.h"
#include "../common/socket.h"

#include "game_state.h"

class ProtocolServer: public Protocol {
private:
    void send_cordinates(const Coordinate& send);


public:
    explicit ProtocolServer(Socket& skt);

    void send_game_estate(const GameState_t& estate);
    uint8_t receive_count_players();

    ~ProtocolServer();
};

#endif  // SERVER_PROTOCOL_SERVER_H_