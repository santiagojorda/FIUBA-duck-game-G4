#ifndef MAP
#define MAP

#include <list>

#include "../attributes/positionable.h"

class Map : public std::list<Positionable*>{
private:
public:
    Map() {}
    void add(Positionable* map_item) { this->push_back(map_item); }
    void remove(Positionable* map_item) {
        (void)map_item;
    };

    ~Map() { clear(); }
};

#endif
