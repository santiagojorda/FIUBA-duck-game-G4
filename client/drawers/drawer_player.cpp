#include "drawer_player.h"

#include <map>

#include "../../common/orientations.h"
#include "../game_state/player.h"

#define TILE_SIZE_WEAPON 40

#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& player):
        texture(renderer, textures[player.sprite.id_texture]) {

    animations = {
            {IS_IDLE,
             [this](SDL2pp::Renderer& renderer, const player_t& player) {
                 Animation anim = {DUCK_INITIAL_X, DUCK_INITIAL_Y, 0, 0,
                                   static_cast<orientations>(player.is_looking) == LEFT};
                 draw_animation(renderer, player, anim);
             }},
            {HAS_ARMOR_CLIENT,  // con armadura
             [this](SDL2pp::Renderer& renderer, const player_t& player) {
                 Animation anim = {DUCK_INITIAL_X, DUCK_INITIAL_Y, 0, 3,
                                   static_cast<orientations>(player.is_looking) == LEFT};
                 draw_animation(renderer, player, anim);
                 Animation helmetAnim = {452, 213, -4, -16,
                                         static_cast<orientations>(player.is_looking) == LEFT};
                 draw_animation(renderer, player, helmetAnim);
             }},
            {IS_RUNNING,
             [this](SDL2pp::Renderer& renderer, const player_t& player) {
                 int srcX = DUCK_INITIAL_X + SIZE_DUCK_SPRITE * player.frame;
                 Animation anim = {srcX, DUCK_INITIAL_Y, 0, 0,
                                   static_cast<orientations>(player.is_looking) == LEFT};
                 draw_animation(renderer, player, anim);
             }},

    };
}

void DrawerPlayer::draw_animation(SDL2pp::Renderer& renderer, const player_t& player,
                                  const Animation& anim) {
    renderer.Copy(
            texture, SDL2pp::Rect(anim.src_x, anim.src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
            SDL2pp::Rect(player.sprite.coordinate.get_x() + anim.offset_x,
                         player.sprite.coordinate.get_y() + anim.offset_y, TILE_SIZE, TILE_SIZE),
            0.0, SDL2pp::NullOpt, anim.flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {

    auto it = animations.find(static_cast<DuckState_1>(player.state));
    if (it != animations.end()) {
        it->second(renderer, player);
    }


    /*
        int src_x = DUCK_INITIAL_X;
        int src_y = DUCK_INITIAL_Y;

        int armadura_src_x = 387;
        int armadura_src_y = 11;

        // int armadura_alas_src_x = 580;
        // int armadura_alas_y = 11;

        int casco_src_x = 452;
        int casco_y = 213;

        SDL2pp::Texture armadura(renderer, DATA_PATH "/DuckGame-Equipment.png");

        SDL2pp::Texture armadura_para_alas(renderer, DATA_PATH "/DuckGame-Equipment.png");

        SDL2pp::Texture casco(renderer, DATA_PATH "/DuckGame-Equipment.png");

        SDL2pp::Texture weaponTexture(renderer, DATA_PATH "/DuckGame-Equipment.png");

        if (player.state == IS_RUNNING) {
            src_x = DUCK_INITIAL_X + SIZE_DUCK_SPRITE * player.frame;
            armadura_src_x = 387 + SIZE_DUCK_SPRITE * player.frame;
            // armadura_alas_src_x = 580 + SIZE_DUCK_SPRITE * player.frame;
        } else if (player.state == IS_IDLE) {
            renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                          SDL2pp::Rect(player.sprite.coordinate.get_x(),
                                       player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE),
                          0.0, SDL2pp::NullOpt,
                          static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL
       : SDL_FLIP_NONE); } else if (player.state == 100) {  // posee armadura -> Consultar cual es
       el estado renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE,
       SIZE_DUCK_SPRITE), SDL2pp::Rect(player.sprite.coordinate.get_x(),
                                       player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE),
                          0.0, SDL2pp::NullOpt,
                          player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

            renderer.Copy(
                    armadura,
                    SDL2pp::Rect(armadura_src_x, armadura_src_y, SIZE_DUCK_SPRITE,
       SIZE_DUCK_SPRITE), SDL2pp::Rect(player.sprite.coordinate.get_x(),
       player.sprite.coordinate.get_y() + 3, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                    player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

            renderer.Copy(casco, SDL2pp::Rect(casco_src_x, casco_y, SIZE_DUCK_SPRITE,
       SIZE_DUCK_SPRITE), SDL2pp::Rect(player.sprite.coordinate.get_x() - 4,
                                       player.sprite.coordinate.get_y() - 16, TILE_SIZE, TILE_SIZE),
                          0.0, SDL2pp::NullOpt,
                          player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
        }

        renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x(),
       player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                      static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                             SDL_FLIP_NONE);

        if (static_cast<int>(player.inventory.weapon) != 0) {
            auto& properties =
       weapon_properties[static_cast<TEXTURE_WEAPONS>(player.inventory.weapon)]; weaponTexture =
       SDL2pp::Texture(renderer, properties.texturePath); int weaponsrc_X = properties.src_x; int
       weaponsrc_Y = properties.src_y; int weapon_width = properties.width; int weapon_height =
       properties.height; renderer.Copy(weaponTexture, SDL2pp::Rect(weaponsrc_X, weaponsrc_Y,
       weapon_width, weapon_height), SDL2pp::Rect(player.sprite.coordinate.get_x() + 3,
                                       player.sprite.coordinate.get_y() + 5, TILE_SIZE_WEAPON,
                                       TILE_SIZE_WEAPON));
        }*/
}
