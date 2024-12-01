#ifndef SERVER_PROTOCOL_SERVER_H_
#define SERVER_PROTOCOL_SERVER_H_

#include <cstdint>
#include <string>

#include "../../common/action_events.h"
#include "../../common/protocol.h"
#include "../../common/socket.h"
#include "../game/game_state.h"

class ProtocolServer: public Protocol {
private:
    void send_coordinates(const Coordinate& send);

    void send_inventory(Inventory& inventory);
    void send_gun(Gun* gun);
    void send_armor(Armor* armor);
    void send_helmet(Helmet* helmet);

    void send_players_state(GameState_t& state);
    void send_projectiles_state(GameState_t& state);
    void send_boxes_state(GameState_t& state);
    void send_scenario_state(GameState_t& state);
    void send_throwables_state(GameState_t& state);
    void send_map_guns_state(GameState_t& state);

public:
    explicit ProtocolServer(Socket& skt);

    void send_game_state(GameState_t& state);

    uint8_t receive_count_players();

    void send_new_player(const uint8_t& sender);
    
    void send_count_players(const uint8_t& sender);

    void receive_event(uint8_t& player_id, ActionEvent& event_id);

    ~ProtocolServer();
};

#endif  // SERVER_PROTOCOL_SERVER_H_