#ifndef DRAWER_PLAYER_H
#define DRAWER_PLAYER_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/state_duck.h"
#include "../animation/animation.h"
#include "../animation/animation_loader.h"
#include "../config/game_config.h"
#include "../game_state/player.h"
#include "../textures/textures.h"

#include "drawable.h"
#include "drawer_equipment.h"
#include "drawer_weapon.h"

class DrawerPlayer: public Drawable<Animation> {
private:
    void update_animation(const std::string& type_animation);

    void update_weapon(const player_t& _player, std::map<std::string, AnimationWeapon>& animation);

    void update_wings();

    void update_equipment(const player_t& player,
                          std::map<std::string, AnimationWeapon>& animation_armor,
                          const InventoryDuck& type);

public:
    DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id,
                 std::map<std::string, Animation>& animations, uint8_t is_looking);

    void draw(const player_t& player,
                        std::map<std::string, AnimationWeapon>& animation_weapon,
                        std::map<std::string, AnimationWeapon>& animation_armor);
};

#endif  // DRAWER_PLAYER_H
