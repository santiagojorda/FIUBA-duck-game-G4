#ifndef LIST_PROJECTILES
#define LIST_PROJECTILES

#include "../utils/list_generic.h"

#include "projectile.h"

class ListProjectiles: public ListGeneric<Projectile> {

public:
    ListProjectiles() = default;
    ~ListProjectiles() = default;
};

#endif