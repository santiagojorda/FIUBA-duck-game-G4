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
#include "renderer_helper.h"
#include "weapon_properties.h"

enum TEXTURE_DUCKS {
    DUCK_YELLOW,
    DUCK_GREY,
    DUCK_ORANGE,
    DUCK_WHITE,
};

static std::map<uint8_t, std::string> textures = {
        {DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
        {DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
        {DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
        {DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}};

class DrawerPlayer {
private:
    SDL2pp::Texture texture;

    int get_offset_weapon_x(const player_t& player);

    int get_offset_weapon_y(const player_t& player);

    int get_scale(const player_t& player);

public:
    DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& _player);

    void draw(SDL2pp::Renderer& renderer, const player_t& _player);

    void draw_animation(SDL2pp::Renderer& renderer, const player_t& player, const Animation& anim);
};

#endif  // DRAWER_PLAYER_H
