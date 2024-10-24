#ifndef SERVER_PROTOCOL_SERVER_H_
#define SERVER_PROTOCOL_SERVER_H_

#include <cstdint>
#include <string>

#include "../common/protocol.h"
#include "../common/socket.h"

#include "game_state.h"

class ProtocolServer: public Protocol {

public:
    explicit ProtocolServer(Socket& skt);

    void send_game_estate(const GameState_t& estate);


    ~ProtocolServer();
};

#endif  // SERVER_PROTOCOL_SERVER_H_