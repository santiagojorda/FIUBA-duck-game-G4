#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../common/action_commands.h"
#include "../common/coordinate.h"
#include "../common/protocol.h"
#include "../common/socket.h"

#include "player_position.h"

class ClientProtocol: public Protocol {
private:
    Coordinate receive_cordinates();

public:
    /*
     * Constructor.
     */
    explicit ClientProtocol(Socket& skt);

    /*
     * envia el mensaje de inicio
     */
    void send_init(const uint8_t& init);

    /*
     * envia el mensaje de inicio
     */
    void send_action(int& id_jugador, uint8_t& type_action);

    /*
     *
     */
    std::vector<PlayerPosition_t> receiver_players_();

    /*
     * Deshabilitar copias.
     */
    ClientProtocol(const ClientProtocol&) = delete;
    ClientProtocol& operator=(const ClientProtocol&) = delete;
};

#endif  // CLIENT_PROTOCOL_H
