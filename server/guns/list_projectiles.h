#ifndef LIST_PROJECTILES
#define LIST_PROJECTILES

#include <list>

class Projectile;

class ListProjectiles: public std::list<Projectile*> {
public:
    ListProjectiles() {}
    void add_projectile(Projectile* new_projectile) { this->push_back(new_projectile); };
    void remove_projectile(Projectile* new_projectile) { this->remove(new_projectile); };
    ~ListProjectiles() {
        // for (auto* projectile : *this){
        //     delete projectile;
        // }
    }
};

#endif
