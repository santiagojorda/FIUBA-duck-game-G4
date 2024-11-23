#include "drawable.h"

Drawable::Drawable(SDL2pp::Renderer& renderer, bool flip):
        renderer(renderer),
        flip(flip),
        animations(),
        texture(nullptr),
        coordenada_x(0),
        coordenada_y(0),
        scale_width(0),
        scale_height(0) {}

void Drawable::render(const SDL2pp::Rect& rect) {
    if (this->texture) {  // verifica que la textura no sea un puntero nulo
        this->renderer.Copy(*this->texture, rect,
                            SDL2pp::Rect(coordenada_x, coordenada_y, scale_width, scale_height),
                            0.0, SDL2pp::NullOpt, this->flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    } else {
        throw std::runtime_error("Drawable::render: No texture available for rendering.");
    }
}

Drawable::~Drawable() {}
