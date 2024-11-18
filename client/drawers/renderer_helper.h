#ifndef RENDERER_HELPER_H
#define RENDERER_HELPER_H

struct RenderConfig {
    SDL2pp::Texture& texture;
    int src_x, src_y, src_w, src_h;
    bool flip;

    RenderConfig(SDL2pp::Texture& texture, int x, int y, int w, int h, bool flip):
            texture(texture), src_x(x), src_y(y), src_w(w), src_h(h), flip(flip) {}

    void adjust_for_frame(int frame, int frame_width) { src_x += frame * frame_width; }
};

class RendererHelper {
public:
    static void render(const RenderConfig& config, SDL2pp::Renderer& renderer, int dst_x, int dst_y,
                       int dst_w, int dst_h) {
        renderer.Copy(config.texture,
                      SDL2pp::Rect(config.src_x, config.src_y, config.src_w, config.src_h),
                      SDL2pp::Rect(dst_x, dst_y, dst_w, dst_h), 0.0, SDL2pp::NullOpt,
                      config.flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    }
};

#endif  // RENDERER_HELPER_H
