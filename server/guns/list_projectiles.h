#ifndef LIST_PROJECTILES
#define LIST_PROJECTILES

#include <cstdint>
#include <list>

class ListProjectiles: public std::list<uint8_t> {
private:
public:
    ListProjectiles() {}

    void addPlayer(const uint8_t& player_id) { this->push_back(player_id); }

    void removePlayer(const uint8_t& player_id) { this->remove(player_id); }

    ~ListProjectiles() {}
};

#endif
