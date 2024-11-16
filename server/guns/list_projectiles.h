#ifndef LIST_PROJECTILES
#define LIST_PROJECTILES

#include "projectile.h" 
#include "../utils/list_generic.h"

class ListProjectiles : public ListGeneric<Projectile>{

public:
    ListProjectiles() = default;
    ~ListProjectiles() = default;
};

#endif