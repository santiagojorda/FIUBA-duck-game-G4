#ifndef MAP_DESERIALIZE_H
#define MAP_DESERIALIZE_H

#include <list>
#include <vector>
#include <utility>

#include <yaml-cpp/yaml.h>

#include "../map/map.h"

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

    void load_floors(Map charge_map);

    void load_inicial_points(std::vector<Coordinate>& points);

    void load_weapons(std::list<data_weapon>& data_weapons);


    ~MapDeserialize();
};


#endif  // MAP_DESERIALIZE_H
