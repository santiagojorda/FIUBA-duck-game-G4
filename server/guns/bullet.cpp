#include "bullet.h"

#define TEXTURE_ID 99  // cambiar

Bullet::Bullet(const ProjectileRange& _range_tiles, const Coordinate& _coordinate):
        Projectile(TEXTURE_ID, _range_tiles, _coordinate)  // cambiar
{}