#include "drawable.h"

std::map<std::string, Animation> Drawable::empty_animations = {};

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

void Drawable::render_with_rect(int sprite_x, int sprite_y, int sprite_width, int sprite_height) {
    if (this->texture) {
        this->renderer.Copy(*this->texture,
                            SDL2pp::Rect(sprite_x, sprite_y, sprite_width, sprite_height),
                            SDL2pp::Rect(coordenada_x, coordenada_y, scale_width, scale_height));
    } else {
        throw std::runtime_error("Drawable::render: No texture available for rendering.");
    }
}

// Texture no es copiable
// void Drawable::set_texture(SDL2pp::Texture&& _texture) { this->texture = std::move(_texture); }

void Drawable::set_texture(const std::shared_ptr<SDL2pp::Texture>& _texture) {
    // this->texture = _texture;
    this->texture = std::move(_texture);
}

Drawable::~Drawable() {}
