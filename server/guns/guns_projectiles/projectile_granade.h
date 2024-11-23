#ifndef PROJECTILE_GRANADE_H
#define PROJECTILE_GRANADE_H

#include "../attributes/statable.h"

#include "projectile.h"


class ProjectileGranade: Projectile, Statable {
private:
    /* data */
public:
    ProjectileGranade(/* args */);
    ~ProjectileGranade();
};

ProjectileGranade::ProjectileGranade(/* args */) {}

ProjectileGranade::~ProjectileGranade() {}


#endif  // PROJECTILE_GRANADE_H
