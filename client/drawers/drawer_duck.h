#ifndef DRAWER_DUCK_H
#define DRAWER_DUCK_H

#include <chrono>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "drawable.h"

class DrawerDuck: public Drawable {
private:
    SDL2pp::Texture texture;
    int x;
    int y;
    int run_phase;
    bool is_moving_left;
    std::chrono::time_point<std::chrono::high_resolution_clock> last_animation_time;
    const std::chrono::milliseconds animation_interval;

public:
    DrawerDuck(SDL2pp::Renderer& renderer);
    void update_animation(bool isRunning);
    void draw(SDL2pp::Renderer& renderer) override;  // o dejar el is_moving_left como atributo
    void set_position(int x, int y);
    void set_is_moving_left(bool is_moving_left);
};

#endif  // DRAWER_DUCK_H