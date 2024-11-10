#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../../common/action_commands.h"
#include "../../common/coordinate.h"
#include "../../common/protocol.h"
#include "../../common/socket.h"
#include "../game_state/client_game_state.h"
#include "../player_position.h"
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

    void receive_cordinates(Coordinate& coordinate);

    void receive_players(VectorPlayers& players);

    void receive_bullets(std::vector<bullet_t>& bullets);

    void receive_throwables(VectorThrowable& throwables);

    void receive_boxes(std::vector<box_t>& boxes);

    void receive_floor_sprites(VectorSprite& floor_sprites);

    void receive_sprite(sprite_t& sprite);

    void receive_inventory(inventory_t& inventory);


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
     *
     */
    void send_action(uint8_t& id_jugador, ActionCommand& type_action);

    /*
     *
     */
    void receive_zoom_details(zoom_t zoom);

    /*
     *
     */
    std::vector<PlayerPosition_t> receiver_players_();

    /*
     *
     */
    client_game_state_t receive_game_state();

    /*
     * Deshabilitar copias.
     */
    ClientProtocol(const ClientProtocol&) = delete;
    ClientProtocol& operator=(const ClientProtocol&) = delete;
};

#endif  // CLIENT_PROTOCOL_H