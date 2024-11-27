#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <map>
#include <memory>
#include <stdexcept>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../animation/animation.h"
#include "../textures/texture_provider.h"

class Drawable {
protected:
    TextureProvider& texture_provider;
    SDL2pp::Renderer& renderer;
    std::unique_ptr<SDL2pp::Texture> texture;
    std::map<std::string, Animation>& animations;
    bool flip;
    int coordenada_x;
    int coordenada_y;
    int scale_width;
    int scale_height;
    int frame;
    std::string type_animation;

public:
    Drawable(SDL2pp::Renderer& renderer, std::map<std::string, Animation>& animations);

    Drawable(SDL2pp::Renderer& renderer, std::unique_ptr<SDL2pp::Texture> texture,
             std::map<std::string, Animation>& animations);

    void render();

    virtual ~Drawable();
};

#endif  // DRAWABLE_H
