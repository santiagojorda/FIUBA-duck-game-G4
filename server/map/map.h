#ifndef MAP
#define MAP

#include <list>
#include <memory>
#include "../map/ground.h"

class Map: public std::list<std::shared_ptr<Ground>> {
private:
public:
    Map() {}
    void add(std::shared_ptr<Ground> map_item) { this->push_back(map_item); }
    void remove(std::shared_ptr<Ground> map_item) { (void)map_item; };

    ~Map() { 
        clear(); 
    }
};

#endif
