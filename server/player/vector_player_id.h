#ifndef VECTOR_PLAYERS_ID
#define VECTOR_PLAYERS_ID

#include <algorithm>
#include <cstdint>
#include <vector>

class VectorPlayerID: public std::vector<uint8_t> {
private:
public:
    VectorPlayerID() {}

    void addPlayer(const uint8_t& _player_id) { this->push_back(_player_id); }

    void removePlayer(const uint8_t& _pos) { this->erase(begin() + _pos); }

    ~VectorPlayerID() {}
};

#endif
