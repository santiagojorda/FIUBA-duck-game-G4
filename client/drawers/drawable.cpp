#include "drawable.h"

Drawable::Drawable(SDL2pp::Renderer& renderer, std::map<std::string, Animation>& animations):
        texture_provider(TextureProvider::get_instance()),
        renderer(renderer),
        texture(nullptr),
        animations(animations),
        flip(false),
        coordenada_x(0),
        coordenada_y(0),
        scale_width(0),
        scale_height(0),
        frame(0),
        type_animation("") {}

Drawable::Drawable(SDL2pp::Renderer& renderer, std::unique_ptr<SDL2pp::Texture> texture,
                   std::map<std::string, Animation>& animations):
        texture_provider(TextureProvider::get_instance()),
        renderer(renderer),
        texture(std::move(texture)),
        animations(animations),
        flip(false),
        coordenada_x(0),
        coordenada_y(0),
        scale_width(0),
        scale_height(0),
        frame(0),
        type_animation("") {}

void Drawable::render() {
    auto anim_rect = this->animations[this->type_animation].get_current_frame(this->frame);

    if (this->texture) {
        this->renderer.Copy(*this->texture, anim_rect,
                            SDL2pp::Rect(coordenada_x, coordenada_y, scale_width, scale_height),
                            0.0, SDL2pp::NullOpt, this->flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    } else {
        throw std::runtime_error("Drawable::render: No texture available for rendering.");
    }
}

Drawable::~Drawable() {}
