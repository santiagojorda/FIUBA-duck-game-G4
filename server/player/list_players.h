#ifndef LIST_PLAYERS
#define LIST_PLAYERS

#include <list>

#include "algorithm"
#include "player.h"

class ListPlayers: public std::list<Player> {
private:
public:
    ListPlayers() {}

    void addPlayer(const Player& _player) { this->push_back(_player); }

    ListPlayers(const ListPlayers& _list): std::list<Player>(_list) {}

    ListPlayers& operator=(const ListPlayers& _list) {
        if (this != &_list) {
            this->clear();
            this->insert(this->end(), _list.begin(), _list.end());
        }
        return *this;
    }

    ~ListPlayers() {}
};

#endif
