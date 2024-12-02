#include "map_deserialize.h"

#include <map>

#include "../map/ground.h"
#include "../map/box.h"

enum keys_yamel {
    MAP_ID,
    TILE_SIZE,
    TILES,
    TILE_ID,
    PLAYER_SIZE,
    PLAYERS,
    WEAPON_SIZE,
    WEAPONS,
    COORDINATE,
    X,
    Y,
    ID,
    BOX_ID,
    BOX_SIZE,
    BOXES
};

std::map<keys_yamel, std::string> keys_string = {{MAP_ID, "map_id"},
                                                 {TILE_SIZE, "tile_size"},
                                                 {TILES, "tiles"},
                                                 {TILE_ID, "tile_id"},
                                                 {PLAYER_SIZE, "player_size"},
                                                 {PLAYERS, "players"},
                                                 {WEAPON_SIZE, "weapon_size"},
                                                 {WEAPONS, "weapons"},
                                                 {COORDINATE, "coordinate"},
                                                 {X, "x"},
                                                 {Y, "y"},
                                                 {ID, "id"},
                                                 {BOX_ID, "box_id"},
                                                 {BOX_SIZE, "box_size"},
                                                 {BOXES, "boxes"}};

std::string enum_string(keys_yamel key) { return keys_string[key]; }

MapDeserialize::MapDeserialize(const std::string& path): map(YAML::LoadFile(path)) {}

void MapDeserialize::load_floors(Map& charge_map) {
    int tile_size = this->map[enum_string(TILE_SIZE)].as<int>();
    YAML::Node tiles = this->map[enum_string(TILES)];
    for (const auto& tile: tiles) {
        int tile_id = tile[enum_string(TILE_ID)].as<int>();
        // int map_id = tile[enum_string(MAP_ID)].as<int>();
        int x = tile[enum_string(COORDINATE)][enum_string(X)].as<int>();
        int y = tile[enum_string(COORDINATE)][enum_string(Y)].as<int>();

        charge_map.add(std::make_shared<Ground>(Coordinate(x, y, tile_size, tile_size), tile_id));
    }
}

void MapDeserialize::load_boxes(ListBoxes& map_boxes) {
    int box_size = this->map[enum_string(BOX_SIZE)].as<int>();
    YAML::Node boxes = this->map[enum_string(BOXES)];
    for (const auto& box: boxes) {
        // int box_id = box[enum_string(BOX_ID)].as<int>();
        int x = box[enum_string(COORDINATE)][enum_string(X)].as<int>();
        int y = box[enum_string(COORDINATE)][enum_string(Y)].as<int>();

        map_boxes.emplace_back(Coordinate(x, y, box_size, box_size));
    }
}

void MapDeserialize::load_inicial_points(std::vector<Coordinate>& points) {
    int player_size = this->map[enum_string(PLAYER_SIZE)].as<int>();
    YAML::Node players = this->map[enum_string(PLAYERS)];
    for (const auto& player: players) {
        int x = player[enum_string(COORDINATE)][enum_string(X)].as<int>();
        int y = player[enum_string(COORDINATE)][enum_string(Y)].as<int>();
        points.emplace_back(x, y, player_size, player_size);
    }
}

void MapDeserialize::load_weapons(std::list<data_weapon>& data_weapons) {
    int weapon_size = this->map[enum_string(WEAPON_SIZE)].as<int>();
    YAML::Node weapons = this->map[enum_string(WEAPONS)];
    for (const auto& weapon: weapons) {
        int id = weapon[enum_string(ID)].as<int>();
        int x = weapon[enum_string(COORDINATE)][enum_string(X)].as<int>();
        int y = weapon[enum_string(COORDINATE)][enum_string(Y)].as<int>();
        Coordinate coordinate(x, y, weapon_size, weapon_size);
        data_weapons.emplace_back(id, coordinate);
    }
}


MapDeserialize::~MapDeserialize() {}
