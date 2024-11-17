#ifndef DRAWER_PLAYER_H
#define DRAWER_PLAYER_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/state_duck.h"
#include "../../common/weapons_id.h"
#include "../config/game_config.h"
#include "../game_state/player.h"

#include "animation.h"
#include "weapon_properties.h"

enum TEXTURE_DUCKS {
    DUCK_YELLOW,
    DUCK_GREY,
    DUCK_ORANGE,
    DUCK_WHITE,
};

enum DuckState_1 : uint8_t {
    IS_JUMPING_CLIENT,
    IS_RUNNING_CLIENT,
    IS_CROUCHING_CLIENT,
    IS_RECOILING_CLIENT,
    IS_FALLING_CLIENT,
    IS_SLIPPING_CLIENT,
    IS_PLANING_CLIENT,
    IS_IDLE_CLIENT,
    IS_DEAD_CLIENT,
    HAS_ARMOR_CLIENT,
};

static std::map<uint8_t, std::string> textures = {
        {DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
        {DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
        {DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
        {DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}};

class DrawerPlayer {
private:
    SDL2pp::Texture texture;

    std::map<DuckState_1, std::function<void(SDL2pp::Renderer&, const player_t&)>> animations;

public:
    DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& _player);

    void draw(SDL2pp::Renderer& renderer, const player_t& _player);

    void draw_animation(SDL2pp::Renderer& renderer, const player_t& player, const Animation& anim);
};

#endif  // DRAWER_PLAYER_H
