#ifndef VECTOR_SPRITE_H
#define VECTOR_SPRITE_H

#include <vector>
#include "sprite.h"

class VectorSprite : public std::vector<srprite_t>{
private:
public:
    VectorSprite();
    ~VectorSprite();
};

VectorSprite::VectorSprite()
{
}

VectorSprite::~VectorSprite()
{
}







#endif // VECTOR_SPRITE_H
