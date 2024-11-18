#ifndef DRAWER_BULLET_H
#define DRAWER_BULLET_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../game_state/elements.h"

#include "drawable.h"

class DrawerBullet {
private:
    bullet_t bullet;
    SDL2pp::Texture texture;

public:
    DrawerBullet(bullet_t bullet, SDL2pp::Renderer& renderer);
    void draw(SDL2pp::Renderer& renderer);

    void update_bullet(const bullet_t& update_bullet);
};

#endif  // DRAWER_BULLET_H
