#ifndef MAP
#define MAP

#include <list>

#include "../attributes/positionable.h"

class Map {
private:
    std::list<Positionable*> items;  // esta deberia ser otro objeto, llamado map_item porque
                                     // positionable puede ser cualquiera
public:
    Map() {}


    void add(Positionable* map_item) { items.push_back(map_item); }
    void remove(Positionable* map_item) {
        (void)map_item;

        // ver
    };
    void clear() {
        // for (Positionable* item : items){
        //     delete item;
        // }
    }
    ~Map() { clear(); }
};

#endif
