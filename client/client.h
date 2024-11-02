#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "../common/socket.h"

#include "drawer.h"
#include "protocol_client.h"

class Client {
private:
    // cppcheck-suppress unusedStructMember
    const std::string hostname;
    // cppcheck-suppress unusedStructMember
    const std::string servicename;
    Socket skt;
    ClientProtocol protocol;
    Drawer drawer;

public:
    /*
     * Constructor.
     */
    Client(const std::string& hostname, const std::string& servname);

    /*
     * Constructor para mas jugadores.
     */
    Client(const std::string& hostname, const std::string& servname, int N_players);

    /*
     * Constructor default.
     */
    Client();

    /*
     * Se realiza la comunicación con el servidor, mediante el envío y recepción de mensajes.
     */
    void run();

    /*
     * Deshabilitar copias.
     */
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
};

#endif  // CLIENT_H
