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
    std::unique_ptr<SDL2pp::Texture>
            texture;  // -> SDL2pp::Texture no tiene un constructor por defecto.

public:
    Drawable(SDL2pp::Renderer& renderer, bool flip);

    void render(const SDL2pp::Rect& rect, int coor_x, int coor_y, int scale_w, int scale_h);

    virtual ~Drawable();
};

#endif  // DRAWABLE_H
