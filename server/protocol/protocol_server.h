#ifndef SERVER_PROTOCOL_SERVER_H_
#define SERVER_PROTOCOL_SERVER_H_

#include <cstdint>
#include <string>

#include "../../common/protocol.h"
#include "../../common/socket.h"

#include "../game/game_state.h"

class ProtocolServer: public Protocol {
private:
    void send_cordinates(const Coordinate& send);

    void send_inventory(Inventory& inventory);
    void send_gun(Gun* gun);
    void send_armor(Armor* armor);
    void send_helmet(Helmet* helmet);

    void send_players_state(GameState_t& state);
    void send_projectiles_state(GameState_t& state);
    void send_boxes_state(GameState_t& state);
    void send_scenario_state(GameState_t& state);
    void send_camera_state(GameState_t& state);

public:
    explicit ProtocolServer(Socket& skt);

    void send_game_state(GameState_t& state);

    uint8_t receive_count_players();

    void receive_event(uint8_t& player_id, uint8_t& event_id);

    ~ProtocolServer();
};

#endif  // SERVER_PROTOCOL_SERVER_H_