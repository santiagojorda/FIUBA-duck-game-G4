#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <map>
#include <memory>
#include <stdexcept>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

template <typename AnimationType>
class Drawable {
protected:
    SDL2pp::Renderer& renderer;
    std::unique_ptr<SDL2pp::Texture> texture;
    bool flip;
    std::map<std::string, AnimationType>& animations;
    int coordenada_x;
    int coordenada_y;
    int scale_width;
    int scale_height;
    int frame;

public:
    Drawable(SDL2pp::Renderer& renderer, std::unique_ptr<SDL2pp::Texture> texture,
             std::map<std::string, AnimationType>& animations, bool flip = false);

    Drawable(SDL2pp::Renderer& renderer, std::map<std::string, AnimationType>& animations,
             bool flip = false);

    void render(const SDL2pp::Rect& rect);

    virtual ~Drawable();
};

template <typename AnimationType>
Drawable<AnimationType>::Drawable(SDL2pp::Renderer& renderer,
                                  std::unique_ptr<SDL2pp::Texture> texture,
                                  std::map<std::string, AnimationType>& animations, bool flip):
        renderer(renderer),
        texture(std::move(texture)),
        flip(flip),
        animations(animations),
        coordenada_x(0),
        coordenada_y(0),
        scale_width(0),
        scale_height(0),
        frame(0) {}

// Constructor solo con animaciones
template <typename AnimationType>
Drawable<AnimationType>::Drawable(SDL2pp::Renderer& renderer,
                                  std::map<std::string, AnimationType>& animations, bool flip):
        renderer(renderer),
        texture(nullptr),
        flip(flip),
        animations(animations),
        coordenada_x(0),
        coordenada_y(0),
        scale_width(0),
        scale_height(0),
        frame(0) {}

template <typename AnimationType>
void Drawable<AnimationType>::render(const SDL2pp::Rect& rect) {
    if (this->texture) {
        this->renderer.Copy(*this->texture, rect,
                            SDL2pp::Rect(coordenada_x, coordenada_y, scale_width, scale_height),
                            0.0, SDL2pp::NullOpt, this->flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    } else {
        throw std::runtime_error("Drawable::render: No texture available for rendering.");
    }
}

template <typename AnimationType>
Drawable<AnimationType>::~Drawable() {}

#endif  // DRAWABLE_H
