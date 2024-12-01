#ifndef GROUND
#define GROUND

#include <cstdint>

#define GROUND_SIZE 16
#define NATURE_TILESET_ID 0
class Ground{
protected:
    uint8_t texture_id;
    uint8_t map_id;
public:
    explicit Ground(const uint8_t& _texture_id, const uint8_t& _map_id):
        texture_id(_texture_id),
        map_id(_map_id)
        {}
    uint8_t get_map_id() { return map_id; }
    uint8_t get_texture_id() { return texture_id; }
    ~Ground() {}
};

#endif