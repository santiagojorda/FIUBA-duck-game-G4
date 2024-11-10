#include "protocol_server.h"

#include "../equipment/armor.h"
#include "../equipment/helmet.h"

#define BYTE_CLIENT 0xA

ProtocolServer::ProtocolServer(Socket& skt): Protocol(skt) {}

void ProtocolServer::send_cordinates(const Coordinate& send) {
    send_2_bytes(send.get_x());
    send_2_bytes(send.get_y());
    send_2_bytes(send.get_h());
    send_2_bytes(send.get_w());
}

void ProtocolServer::send_inventory(Inventory& inventory) {
    send_gun(inventory.get_gun());
    send_armor(inventory.get_armor());
    send_helmet(inventory.get_helmet());
}

void ProtocolServer::send_gun(Gun* gun) {
    if (gun) {
        send_byte(gun->get_id());
        send_byte(gun->get_ammo());
    } else {
        send_byte(false);
    }
}

void ProtocolServer::send_armor(Armor* armor) {
    if (armor) {
        send_byte(armor->get_texture_id());
    } else {
        send_byte(false);
    }
}
void ProtocolServer::send_helmet(Helmet* helmet) {
    if (helmet) {
        send_byte(helmet->get_texture_id());
    } else {
        send_byte(false);
    }
}

void ProtocolServer::send_players_state(GameState_t& state) {
    uint8_t count_players = state.players.size();
    send_byte(count_players);
    for (Player& player: state.players) {
        send_byte(player.get_id());
        send_cordinates(player.get_coordinate());
        send_byte(static_cast<uint8_t>(player.get_direction()));
        send_byte(static_cast<uint8_t>(player.get_state()));
        send_byte(static_cast<uint8_t>(player.get_frame()));
        send_inventory(player.get_inventory());
    }
}

void ProtocolServer::send_projectiles_state(GameState_t& state) {
    (void)state;
    uint16_t count_projectiles = 0;
    send_2_bytes(count_projectiles);
    if (count_projectiles > 0) {
        send_byte(0);                   // texture_id
        send_cordinates(Coordinate());  // posicion del escenario
        send_byte(0);                   // frame
    }
}


void ProtocolServer::send_throwables_state(GameState_t& state) {
    (void)state;
    uint8_t count_throwables = 0;
    send_byte(count_throwables);
    if (count_throwables > 0) {
        send_byte(0);                   // texture_id
        send_cordinates(Coordinate());  // posicion de la bomba
        send_byte(0);                   // frame
        send_byte(0);                   // state
    }
}

void ProtocolServer::send_boxes_state(GameState_t& state) {
    (void)state;
    uint8_t count_boxes = 0;
    send_byte(count_boxes);  //
    if (count_boxes > 0) {
        send_byte(0);                   // texture_id
        send_cordinates(Coordinate());  // posicion del escenario
        send_byte(0);                   // frame
    }
}

void ProtocolServer::send_scenario_state(GameState_t& state) {
    (void)state;
    uint8_t count_map_items = 0;
    send_byte(count_map_items);  //
    if (count_map_items > 0) {
        send_byte(0);                   // texture_id
        send_cordinates(Coordinate());  // posicion del escenario
    }
}

void ProtocolServer::send_camera_state(GameState_t& state) {
    (void)state;
    send_2_bytes(0);  // zoom_min
    send_2_bytes(0);  // zoom_max
}


void ProtocolServer::send_map_weapons_state(GameState_t& state) {
    (void)state;
    uint8_t count_map_weapons = 0;
    send_byte(count_map_weapons);  //
    if (count_map_weapons > 0) {
        send_byte(0);                   // texture_id
        send_cordinates(Coordinate());  // posicion del escenario
    }
}

void ProtocolServer::send_game_state(GameState_t& state) {
    send_players_state(state);
    send_projectiles_state(state);
    send_throwables_state(state);
    send_boxes_state(state);
    send_scenario_state(state);
    send_map_weapons_state(state);
    // send_camera_state(state);
}

uint8_t ProtocolServer::receive_count_players() {
    uint8_t count_players = 0;
    receive_byte(count_players);
    return count_players;
}

void ProtocolServer::receive_event(uint8_t& player_id, uint8_t& event_id) {
    uint8_t code_client = 0;
    receive_byte(code_client);
    if (code_client == BYTE_CLIENT) {
        receive_byte(player_id);
        receive_byte(event_id);
    }
}


ProtocolServer::~ProtocolServer() {}
