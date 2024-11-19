#include "protocol_client.h"

ClientProtocol::ClientProtocol(Socket& skt): Protocol(skt) {}

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
}

void ClientProtocol::receive_sprite(sprite_t& sprite) {
    uint8_t id_texture;
    this->receive_byte(id_texture);
    Coordinate coordinate;
    receive_cordinates(coordinate);
    sprite = sprite_t{id_texture, coordinate};
}

void ClientProtocol::send_action(uint8_t& id_jugador, ActionCommand& type_action) {
    std::vector<uint8_t> vector_data;
    vector_data.push_back(HEADER_CLIENT);
    vector_data.push_back(id_jugador);
    vector_data.push_back(type_action);
    this->skt.sendall(vector_data.data(), vector_data.size(), &this->was_closed);
}

void ClientProtocol::send_init(const uint8_t& init) { this->send_byte(init); }

void ClientProtocol::receive_inventory(inventory_t& inventory) {
    uint8_t weapon = 0;  // es el "id_arma"
    uint8_t ammo = 0;
    uint8_t armor = 0;
    uint8_t helmet = 0;

    this->receive_byte(weapon);

    if (weapon != 0) {
        this->receive_byte(ammo);
    }
    this->receive_byte(armor);
    this->receive_byte(helmet);

    inventory = inventory_t{weapon, ammo, armor, helmet};
}

void ClientProtocol::receive_players(VectorPlayers& players) {
    uint8_t cantidad_players;
    this->receive_byte(cantidad_players);

    VectorPlayers players_positions;

    for (size_t i = 0; i < cantidad_players; i++) {
        sprite_t sprite;
        receive_sprite(sprite);

        uint8_t is_looking;
        this->receive_byte(is_looking);

        uint8_t state;  // accion del pato. si es 0x0 no hace nada
        this->receive_byte(state);

        uint8_t frame;
        this->receive_byte(frame);

        inventory_t inventory;
        receive_inventory(inventory);
        player_t player_position{sprite, is_looking, state, frame, inventory};
        players_positions.push_back(player_position);
    }

    players = players_positions;
}

// balas -> recibo cantidad y sigo leyendo
void ClientProtocol::receive_bullets(std::vector<bullet_t>& _bullets) {
    uint16_t cantidad_bullets;
    this->receive_2_bytes(cantidad_bullets);

    for (size_t i = 0; i < cantidad_bullets; i++) {
        sprite_t sprite;
        receive_sprite(sprite);
        uint8_t frame = 0x0;
       // this->receive_byte(frame);
        bullet_t bullet{sprite, frame};
        _bullets.push_back(bullet);
    }
}

void ClientProtocol::receive_throwables(VectorThrowable& _throwables) {
    uint8_t cantidad_throwables;
    this->receive_byte(cantidad_throwables);

    VectorThrowable throwables;

    for (size_t i = 0; i < cantidad_throwables; i++) {
        sprite_t sprite;
        receive_sprite(sprite);
        uint8_t frame;
        this->receive_byte(frame);
        uint8_t state;
        this->receive_byte(state);
        throwable_t throwable{sprite, frame, state};
        throwables.push_back(throwable);
    }

    _throwables = throwables;
}

void ClientProtocol::receive_boxes(std::vector<box_t>& _boxes) {
    uint8_t cantidad_boxes;
    this->receive_byte(cantidad_boxes);

    std::vector<box_t> boxes;
    for (size_t i = 0; i < cantidad_boxes; i++) {
        sprite_t sprite;
        receive_sprite(sprite);
        uint8_t frame;
        this->receive_byte(frame);
        box_t box{sprite, frame};
        boxes.push_back(box);
    }

    _boxes = std::move(boxes);  // para evitar copiar y mejorar eficiencia
}

void ClientProtocol::receive_floor_sprites(VectorSprite& _floor_sprites) {
    uint8_t cantidad_floor_sprites;
    this->receive_byte(cantidad_floor_sprites);

    VectorSprite sprites;

    for (size_t i = 0; i < cantidad_floor_sprites; i++) {
        sprite_t sprite;
        receive_sprite(sprite);
        sprites.push_back(sprite);
    }

    _floor_sprites = sprites;
}

zoom_t ClientProtocol::receive_zoom_details() {
    uint16_t zoom_min;
    this->receive_2_bytes(zoom_min);
    uint16_t zoom_max;
    this->receive_2_bytes(zoom_max);
    return zoom_t{zoom_min, zoom_max};
}

void ClientProtocol::receive_weapons(VectorSprite& _weapons) {
    uint8_t cantidad_weapons;
    this->receive_byte(cantidad_weapons);

    VectorSprite sprites;

    for (size_t i = 0; i < cantidad_weapons; i++) {
        sprite_t sprite;
        receive_sprite(sprite);
        sprites.push_back(sprite);
    }

    _weapons = sprites;
}

void ClientProtocol::receive_game_state(client_game_state_t& game_state) {
    VectorPlayers players;
    receive_players(players);
    std::vector<bullet_t> bullets;
    receive_bullets(bullets);
    VectorThrowable throwables;
    receive_throwables(throwables);
    std::vector<box_t> boxes;
    receive_boxes(boxes);
    VectorSprite sprites;
    receive_floor_sprites(sprites);
    VectorSprite weapons;
    receive_weapons(weapons);

    game_state = client_game_state_t{players, bullets, throwables, boxes, sprites, weapons};
}
