#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>
#include "animation.h"
#include <map>

class Drawable {
protected:
    // a todos les estoy mandando el mismo renderer, que sea atributo y listo
    SDL2pp::Renderer& renderer;  
    bool flip;
    std::map<std::string, Animation> animations;
    // SDL2pp::Texture texture; -> SDL2pp::Texture no tiene un constructor por defecto. otra opcion es usando punteros std::unique_ptr<SDL2pp::Texture> texture;

public:
    Drawable(SDL2pp::Renderer& renderer, bool flip);

    void render(const SDL2pp::Rect& rect, int coor_x, int coor_y, int scale_w, int scale_h);

    virtual ~Drawable() = default;
};

#endif  // DRAWABLE_H
