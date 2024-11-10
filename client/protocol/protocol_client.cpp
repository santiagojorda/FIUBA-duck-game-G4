#include "protocol_client.h"

ClientProtocol::ClientProtocol(Socket& skt): Protocol(skt) {}

Coordinate ClientProtocol::receive_cordinates() {
    uint16_t x;
    this->receive_2_bytes(x);
    uint16_t y;
    this->receive_2_bytes(y);
    uint16_t h;
    this->receive_2_bytes(h);
    uint16_t w;
    this->receive_2_bytes(w);
    return Coordinate(x, y, h, w);
}

void ClientProtocol::receive_cordinates(Coordinate& coordinate) {
    uint16_t x;
    this->receive_2_bytes(x);
    uint16_t y;
    this->receive_2_bytes(y);
    uint16_t h;
    this->receive_2_bytes(h);
    uint16_t w;
    this->receive_2_bytes(w);
    coordinate = Coordinate(x, y, h, w);
    std::cout << coordinate << std::endl;
}

sprite_t ClientProtocol::receive_sprite() {
    uint8_t id_texture;  // es el "id_player"
    this->receive_byte(id_texture);
    Coordinate coordinate = receive_cordinates();

    return sprite_t{id_texture, coordinate};
}

void ClientProtocol::send_action(uint8_t& id_jugador,
                                 ActionCommand& type_action) {  // pasarle action
    std::vector<uint8_t> vector_data;
    vector_data.push_back(HEADER_CLIENT);  // 1 byte
    vector_data.push_back(id_jugador);     // 1 byte
    vector_data.push_back(type_action);    // 1 byte
    this->skt.sendall(vector_data.data(), vector_data.size(), &this->was_closed);
}

std::vector<PlayerPosition_t> ClientProtocol::receiver_players_() {
    uint8_t cantidad_players;
    this->receive_byte(cantidad_players);

    std::vector<PlayerPosition_t> players_positions;
    // guardar vector las coordenadas
    for (size_t i = 0; i < cantidad_players; i++) {
        uint8_t id_player;
        this->receive_byte(id_player);

        Coordinate coordinate = this->receive_cordinates();

        PlayerPosition_t player_position{id_player, coordinate};
        players_positions.push_back(player_position);
    }

    // uint8_t camara;
    // this->receive_byte(camara);
    return players_positions;
}

void ClientProtocol::send_init(const uint8_t& init) {
    // envia cantidad de jugadores
    this->send_byte(init);
}

inventory_t ClientProtocol::receive_inventory() {
    // HEADER
    uint8_t weapon = 0;  // es el "id_arma"
    this->receive_byte(weapon);
    uint8_t ammo = 0;
    uint8_t armor = 0;
    uint8_t helmet = 0;

    if (weapon != 0) {
        this->receive_byte(ammo);  // TODO: refactorizar los receive -> hacerlos por referencia y no
                                   // con returns.
    }
    this->receive_byte(armor);
    this->receive_byte(helmet);

    return inventory_t{weapon, ammo, armor, helmet};
}

// -----------------------------------------------------------------------------------------------

VectorPlayers ClientProtocol::receive_players() {
    uint8_t cantidad_players;
    this->receive_byte(cantidad_players);

    VectorPlayers players_positions;

    for (size_t i = 0; i < cantidad_players; i++) {
        sprite_t sprite = receive_sprite();

        uint8_t is_looking;
        this->receive_byte(is_looking);

        // estos 2 sirven para controlar la animación
        uint8_t state;  // accion del pato : running, jump, etc. si es 0x0 no hace nada
        this->receive_byte(state);

        uint8_t frame;  // elegir la animacion
        this->receive_byte(frame);

        inventory_t inventory = receive_inventory();

        player_t player_position{sprite, is_looking, state, frame, inventory};
        players_positions.push_back(player_position);
    }

    return players_positions;
}

std::vector<bullet_t>
        ClientProtocol::receive_bullets() {  // balas -> recibo cantidad y sigo leyendo
    uint16_t cantidad_bullets;
    this->receive_2_bytes(cantidad_bullets);

    std::vector<bullet_t> bullets;

    for (size_t i = 0; i < cantidad_bullets; i++) {
        sprite_t sprite = receive_sprite();
        uint8_t frame;  // elegir la animacion
        this->receive_byte(frame);
        bullet_t bullet{sprite, frame};
        bullets.push_back(bullet);
    }

    return bullets;
}

VectorThrowable ClientProtocol::receive_throwables() {
    uint8_t cantidad_throwables;
    this->receive_byte(cantidad_throwables);

    VectorThrowable throwables;

    for (size_t i = 0; i < cantidad_throwables; i++) {
        sprite_t sprite = receive_sprite();
        uint8_t frame;  // elegir la animacion
        this->receive_byte(frame);
        uint8_t state;
        this->receive_byte(state);
        throwable_t throwable{sprite, frame, state};
        throwables.push_back(throwable);
    }

    return throwables;
}

std::vector<box_t> ClientProtocol::receive_boxes() {
    uint8_t cantidad_boxes;
    this->receive_byte(cantidad_boxes);

    std::vector<box_t> boxes;
    for (size_t i = 0; i < cantidad_boxes; i++) {
        sprite_t sprite = receive_sprite();
        uint8_t frame;  // elegir la animacion
        this->receive_byte(frame);
        box_t box{sprite, frame};
        boxes.push_back(box);
    }

    return boxes;
}

VectorSprite ClientProtocol::receive_floor_sprites() {
    uint8_t cantidad_floor_sprites;
    this->receive_byte(cantidad_floor_sprites);

    VectorSprite sprites;

    for (size_t i = 0; i < cantidad_floor_sprites; i++) {
        sprite_t sprite = this->receive_sprite();
        sprites.push_back(sprite);
    }

    return sprites;
}

zoom_t ClientProtocol::receive_zoom_details() {
    uint16_t zoom_min;
    this->receive_2_bytes(zoom_min);
    uint16_t zoom_max;
    this->receive_2_bytes(zoom_max);
    return zoom_t{zoom_min, zoom_max};
}

client_game_state_t ClientProtocol::receive_game_state() {
    client_game_state_t game_state;
    VectorPlayers players = receive_players();
    std::vector<bullet_t> bullets = receive_bullets();
    VectorThrowable throwables = receive_throwables();
    std::vector<box_t> boxes = receive_boxes();
    VectorSprite sprites = receive_floor_sprites();
    // cargar weapons

    return game_state;
}
