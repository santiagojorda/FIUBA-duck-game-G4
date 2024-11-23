#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "animation.h"

class Drawable {
protected:
    SDL2pp::Renderer& renderer;
    bool flip;
    std::map<std::string, Animation> animations;
    // -> SDL2pp::Texture no tiene un constructor por defecto.
    std::unique_ptr<SDL2pp::Texture> texture;
    int coordenada_x;
    int coordenada_y;
    int scale_width;
    int scale_height;

public:
    Drawable(SDL2pp::Renderer& renderer, bool flip);

    void render(const SDL2pp::Rect& rect);

    virtual ~Drawable();
};

#endif  // DRAWABLE_H
