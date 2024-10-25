#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../common/protocol.h"
#include "../common/socket.h"

class ClientProtocol {
private:
    Socket& skt;
    bool was_closed;

public:
    /*
     * Constructor.
     */
    explicit ClientProtocol(Socket& skt);

    /*
     * Deshabilitar copias.
     */
    ClientProtocol(const ClientProtocol&) = delete;
    ClientProtocol& operator=(const ClientProtocol&) = delete;
};

#endif  // CLIENT_PROTOCOL_H
