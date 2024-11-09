#ifndef LIST_PROJECTILES
#define LIST_PROJECTILES

#include <cstdint>
#include <list>

class ListProjectiles: public std::list<uint8_t> {
private:
public:
    ListProjectiles() {}
    ~ListProjectiles() {}
};

#endif
