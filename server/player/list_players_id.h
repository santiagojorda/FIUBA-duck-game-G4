#ifndef LIST_PLAYERS_ID
#define LIST_PLAYERS_ID

#include <list>

class ListPlayersID: public std::list<uint8_t> {
private:
public:
    ListPlayersID() {}

    void addPlayer(const uint8_t& _player_id) { this->push_back(_player_id); }

    void removePlayer(const uint8_t& _player_id) { this->remove(_player_id); }

    ~ListPlayersID() {}
};

#endif
