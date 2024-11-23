#ifndef BULLET
#define BULLET

#include "../projectile.h"

#define MAX_RANGE_TILES 1  // medio

class Bullet: public Projectile {
public:
    explicit Bullet(const ProjectileRange& _range_tiles, const Coordinate& _coordinate);
    
    virtual void translate() override;
    virtual void translate_x(int pasos) override;
    virtual void translate_y(int pasos) override;

};

#endif
