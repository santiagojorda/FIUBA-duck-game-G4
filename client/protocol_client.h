#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../common/coordinate.h"
#include "../common/protocol.h"
#include "../common/socket.h"

class ClientProtocol: public Protocol {
private:
public:
    /*
     * Constructor.
     */
    explicit ClientProtocol(Socket& skt);

    Coordinate receive_cordinates();
    /*
     * envia el mensaje de inicio
     */
    void send_init(const uint8_t& init);

    /*
     * Deshabilitar copias.
     */
    ClientProtocol(const ClientProtocol&) = delete;
    ClientProtocol& operator=(const ClientProtocol&) = delete;
};

#endif  // CLIENT_PROTOCOL_H
