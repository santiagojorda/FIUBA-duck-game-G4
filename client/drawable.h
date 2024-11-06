#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2pp/Renderer.hh>

class Drawable {
private:
public:
    virtual void draw(SDL2pp::Renderer& renderer) = 0;  // Método virtual puro
    virtual ~Drawable() {};
};

#endif  // DRAWABLE_H
