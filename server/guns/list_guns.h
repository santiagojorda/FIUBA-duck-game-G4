#ifndef LIST_GUNS
#define LIST_GUNS

#include <list>

class Gun;

class ListGuns: public std::list<Gun*> {
private:
public:
    ListGuns() {}
    void add(Gun* gun_item) { this->push_back(gun_item); }
    void remove(Gun* gun_item) { (void)gun_item; };

    ~ListGuns() { clear(); }
};


#endif
