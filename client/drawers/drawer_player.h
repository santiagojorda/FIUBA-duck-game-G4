#ifndef DRAWER_PLAYER_H
#define DRAWER_PLAYER_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Texture.hh>

#include "../../common/state_duck.h"
#include "../config/game_config.h"
#include "../game_state/player.h"

#include "animation.h"
#include "animation_loader.h"
#include "drawable.h"
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

class DrawerPlayer: public Drawable {
private:
    void update_animation(const std::string type_animation, int frame);

public:
    DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id, uint8_t is_looking);


    void draw(const player_t& _player);
};

#endif  // DRAWER_PLAYER_H
