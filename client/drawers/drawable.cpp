#include "drawable.h"

Drawable::Drawable(SDL2pp::Renderer& renderer, bool flip):
        renderer(renderer), flip(flip), animations() {}

void Drawable::render(const SDL2pp::Rect& rect, int coor_x, int coor_y, int scale_w, int scale_h) {
    this->renderer.Copy(this->renderer, rect, SDL2pp::Rect(coor_x, coor_y, scale_w, scale_h), 0.0,
                  SDL2pp::NullOpt, this->flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

Drawable::~Drawable() {}
