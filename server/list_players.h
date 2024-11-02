#ifndef LIST_PLAYERS
#define LIST_PLAYERS

#include <list>
#include "player.h"
#include "algorithm"

class ListPlayers : public std::list<Player> {
private:
public:
    ListPlayers() {}
    
    void addPlayer(const Player& _player) {
        this->push_back(_player);
    }

    ~ListPlayers() {}
};

#endif
