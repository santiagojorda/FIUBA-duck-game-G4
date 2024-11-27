#ifndef DRAWER_WEAPON_H
#define DRAWER_WEAPON_H

#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/coordinate.h"
#include "../../common/direction.h"
#include "../animation/animation_loader.h"
#include "../animation/animation_weapon.h"
#include "../config/game_config.h"
#include "../game_state/sprite.h"
#include "../textures/textures.h"

#include "drawable.h"

class DrawerWeapon: public Drawable<AnimationWeapon> {
private:
    std::string type_weapon;

public:
    DrawerWeapon(SDL2pp::Renderer& renderer, uint8_t texture_id,
                 std::map<std::string, AnimationWeapon>& animations);

    /* Armas que aparecen en el mapa */
    void draw(const sprite_t& weapon);

    /* Armas que son parte del inventario del pato */
    void draw_with_coordinates(const Coordinate& coordinate, uint8_t is_looking);
};

#endif  // DRAWER_WEAPON_H
