#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../../common/action_commands.h"
#include "../../common/coordinate.h"
#include "../../common/protocol.h"
#include "../../common/socket.h"

#include "../player_position.h"
#include "../client_game_state.h"
#include "../zoom/zoom.h"

class ClientProtocol: public Protocol {
private:
    Coordinate receive_cordinates();

    VectorPlayers receive_players();

    std::vector<bullet_t> receive_bullets();

    VectorThrowable receive_throwables();

    std::vector<box_t> receive_boxes();

    VectorSprite receive_floor_sprites();

    sprite_t receive_sprite();

    inventory_t receive_inventory();

    zoom_t receive_zoom_details();


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
    void send_action(uint8_t& id_jugador, ActionCommand& type_action);

    /*
     *
     */
    std::vector<PlayerPosition_t> receiver_players_();

    client_game_state_t receive_game_state();

    /*
     * Deshabilitar copias.
     */
    ClientProtocol(const ClientProtocol&) = delete;
    ClientProtocol& operator=(const ClientProtocol&) = delete;
};

#endif  // CLIENT_PROTOCOL_H
