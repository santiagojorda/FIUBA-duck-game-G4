#ifndef MAP_DESERIALIZE_H
#define MAP_DESERIALIZE_H

#include <list>
#include <utility>

#include <yaml-cpp/yaml.h>

#include "../../common/coordinate.h"

struct data_weapon {
    uint8_t id;
    Coordinate coordinate;
};


class MapDeserialize {
private:
    YAML::Node map;

public:
    explicit MapDeserialize(const std::string& path);

    void load_floors(std::list<Coordinate>& floors);

    void load_inicial_points(std::list<Coordinate>& points);

    void load_weapons(std::list<data_weapon>& data_weapons);


    ~MapDeserialize();
};


#endif  // MAP_DESERIALIZE_H
