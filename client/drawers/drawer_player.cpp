#include "drawer_player.h"

#include <map>

#include "../../common/orientations.h"
#include "../game_state/player.h"

#define TILE_SIZE_WEAPON 38
#define TILE_SIZE_ALA 22

#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32
#define SIZE_DUCK_ALA 16

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& player):
        texture(renderer, textures[player.sprite.id_texture]) {}

void DrawerPlayer::draw_animation(SDL2pp::Renderer& renderer, const player_t& player,
                                  const Animation& anim) {
    renderer.Copy(
            texture, SDL2pp::Rect(anim.src_x, anim.src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
            SDL2pp::Rect(player.sprite.coordinate.get_x() + anim.offset_x,
                         player.sprite.coordinate.get_y() + anim.offset_y, TILE_SIZE, TILE_SIZE),
            0.0, SDL2pp::NullOpt, anim.flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {
    if (player.state == IS_IDLE) {
        renderer.Copy(
                texture,
                SDL2pp::Rect(DUCK_INITIAL_X, DUCK_INITIAL_Y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                SDL2pp::Rect(player.sprite.coordinate.get_x(), player.sprite.coordinate.get_y(),
                             TILE_SIZE, TILE_SIZE),
                0.0, SDL2pp::NullOpt,
                static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                       SDL_FLIP_NONE);
    } else if (player.state == IS_RUNNING) {
        renderer.Copy(texture,
                      SDL2pp::Rect(DUCK_INITIAL_X + SIZE_DUCK_SPRITE * player.frame, DUCK_INITIAL_Y,
                                   SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x(),
                                   player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE),
                      0.0, SDL2pp::NullOpt,
                      static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                             SDL_FLIP_NONE);
    }

    if (static_cast<int>(player.inventory.armor) != 0) {
        SDL2pp::Texture armadura_texture(renderer, DATA_PATH "/DuckGame-Equipment.png");
        renderer.Copy(armadura_texture,
                      SDL2pp::Rect(387 + SIZE_DUCK_SPRITE * player.frame, 11, SIZE_DUCK_SPRITE,
                                   SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x(),
                                   player.sprite.coordinate.get_y() + 3, TILE_SIZE, TILE_SIZE),
                      0.0, SDL2pp::NullOpt,
                      static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                             SDL_FLIP_NONE);

        renderer.Copy(armadura_texture, SDL2pp::Rect(452, 213, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x() - 4,
                                   player.sprite.coordinate.get_y() - 16, TILE_SIZE, TILE_SIZE),
                      0.0, SDL2pp::NullOpt,
                      static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                             SDL_FLIP_NONE);
    }

    if (static_cast<int>(player.inventory.weapon) != 0) {
        auto weapon_props =
                weapon_properties[static_cast<TEXTURE_WEAPONS>(player.inventory.weapon)];
        SDL2pp::Texture weapon_texture(renderer, weapon_props.texturePath);

        auto frame = player.state == IS_RUNNING ? player.frame : 0;

        renderer.Copy(weapon_texture,
                      SDL2pp::Rect(weapon_props.src_x, weapon_props.src_y, weapon_props.width,
                                   weapon_props.height),
                      SDL2pp::Rect(player.sprite.coordinate.get_x() + 7,
                                   player.sprite.coordinate.get_y() + 6, TILE_SIZE_WEAPON,
                                   TILE_SIZE_WEAPON),
                      0.0, SDL2pp::NullOpt,
                      static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                             SDL_FLIP_NONE);
        renderer.Copy(
                texture, SDL2pp::Rect(1 + SIZE_DUCK_ALA * frame, 566, SIZE_DUCK_ALA, SIZE_DUCK_ALA),
                SDL2pp::Rect(player.sprite.coordinate.get_x() + 12,
                             player.sprite.coordinate.get_y() + 15, TILE_SIZE_ALA, TILE_SIZE_ALA),
                0.0, SDL2pp::NullOpt,
                static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                       SDL_FLIP_NONE);
    }
}
