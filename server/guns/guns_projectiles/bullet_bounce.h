#ifndef BULLET_BOUNCE_H
#define BULLET_BOUNCE_H

#include "bullet.h"

class BulletBounce : public Bullet{
private:
    /* data */
public:
    explicit BulletBounce(const ProjectileRange& _range_tiles, const Coordinate& _coordinate);

    void bounce(const Positionable& superfice);

    ~BulletBounce();
};







#endif // BULLET_BOUNCE_H
