#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "../common/queue.h"
#include "../common/socket.h"
#include "drawers/drawer.h"
#include "game_state/client_game_state.h"
#include "protocol/protocol_client.h"

#include "client_receiver.h"
#include "client_sender.h"

class Client {
private:
    Socket skt;
    ClientProtocol protocol;
    Queue<ClientEvent_t> commands;
    Queue<client_game_state_t> game_state;  // estado del juego que se recibe del servidor
    ClientReceiver receiver;
    ClientSender sender;
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

    ~Client();
};

#endif  // CLIENT_H
