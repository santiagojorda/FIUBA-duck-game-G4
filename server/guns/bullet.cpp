#include "bullet.h"

#define TEXTURE_ID_BULLET 99 // CAMBIAR 

Bullet::Bullet(const ProjectileRange& _range_tiles, const Coordinate& _coordinate): Projectile(TEXTURE_ID_BULLET, _range_tiles, _coordinate) {}