#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../common/protocol.h"
#include "../common/socket.h"
#include "../common/coordinate.h"

class ClientProtocol: public Protocol {
private:

public:
    /*
     * Constructor.
     */
    explicit ClientProtocol(Socket& skt);

    Coordinate receive_cordinates();


    /*
     * Deshabilitar copias.
     */
    ClientProtocol(const ClientProtocol&) = delete;
    ClientProtocol& operator=(const ClientProtocol&) = delete;
};

#endif  // CLIENT_PROTOCOL_H
