#ifndef PROJECTILE_GRANADE_H
#define PROJECTILE_GRANADE_H

#include "projectile.h"

#include "../attributes/statable.h"


class ProjectileGranade : Projectile , Statable
{
private:
    /* data */
public:
    ProjectileGranade(/* args */);
    ~ProjectileGranade();
};

ProjectileGranade::ProjectileGranade(/* args */)
{
}

ProjectileGranade::~ProjectileGranade()
{
}









#endif // PROJECTILE_GRANADE_H
