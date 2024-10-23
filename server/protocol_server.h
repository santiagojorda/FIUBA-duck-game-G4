#ifndef PROTOCOL_SERVER_H
#define PROTOCOL_SERVER_H

#include <string>

#include <cstdint>

#include "../common/protocol.h"
#include "../common/socket.h"

class ProtocolServer: public Protocol {

public:
    explicit ProtocolServer(Socket& socket);
};

#endif