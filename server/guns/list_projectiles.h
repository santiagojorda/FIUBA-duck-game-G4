#ifndef LIST_PROJECTILES
#define LIST_PROJECTILES

#include <list>

class Projectile;

class ListProjectiles {
private:
    std::list<Projectile*> projectiles;

public:
    ListProjectiles() {}
    void add(Projectile* new_projectile) { projectiles.push_back(new_projectile); };
    void remove(Projectile* projectile) {
        (void)projectile;
        // ver
    };

    void clear() {
        // for (Projectile* item : projectiles){
        //     (v)
        //     // delete item;
        // }
    }
    ~ListProjectiles() { clear(); }
};

#endif
