#ifndef DRAWER_WEAPON_H
#define DRAWER_WEAPON_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../animation/animation_loader.h"
#include "../animation/animation_weapon.h"
#include "../config/game_config.h"
#include "../game_state/sprite.h"
#include "../textures/textures.h"

#include "drawable.h"
#include "weapon_properties.h"

class DrawerWeapon: public Drawable<AnimationWeapon> {
private:
    std::string type_weapon;

public:
    DrawerWeapon(SDL2pp::Renderer& renderer, uint8_t texture_id);

    void draw(const sprite_t& weapon);
};

#endif  // DRAWER_WEAPON_H
