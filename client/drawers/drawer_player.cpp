#include "drawer_player.h"

#include <map>

#include "../../common/orientations.h"
#include "../game_state/player.h"

#define SCALE_WEAPON 38  // PEW_PEW_LASER, LASER_RIFLE
#define SCALE_GRANADA 24
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

int DrawerPlayer::get_offset_weapon_x(const player_t& player) {
    if (static_cast<orientations>(player.is_looking) == LEFT) {
        return player.sprite.coordinate.get_x() + 5;
    }

    if (static_cast<TEXTURE_WEAPONS>(player.inventory.weapon) == GRANADA) {
        return player.sprite.coordinate.get_x() + 20;
    }

    return player.sprite.coordinate.get_x() + 7;
}

int DrawerPlayer::get_offset_weapon_y(const player_t& player) {
    if (static_cast<TEXTURE_WEAPONS>(player.inventory.weapon) == GRANADA) {
        return player.sprite.coordinate.get_y() + 10;
    }

    return player.sprite.coordinate.get_y() + 6;
}

int DrawerPlayer::get_scale(const player_t& player) {
    if (static_cast<TEXTURE_WEAPONS>(player.inventory.weapon) == GRANADA) {
        return SCALE_GRANADA;
    }

    return SCALE_WEAPON;
}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {
    bool flip = static_cast<orientations>(player.is_looking) == LEFT;

    RenderConfig playerConfig(texture, DUCK_INITIAL_X, DUCK_INITIAL_Y, SIZE_DUCK_SPRITE,
                              SIZE_DUCK_SPRITE, flip);

    int frame = static_cast<DuckState>(player.state) == IS_RUNNING ? player.frame : 0;

    playerConfig.adjust_for_frame(frame, SIZE_DUCK_SPRITE);

    RendererHelper::render(playerConfig, renderer, player.sprite.coordinate.get_x(),
                           player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE);

    if (static_cast<int>(player.inventory.armor) != 0) {
        SDL2pp::Texture armadura_texture(renderer, DATA_PATH "/DuckGame-Equipment.png");
        RenderConfig armorConfig(armadura_texture, 387, 11, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE,
                                 flip);
        armorConfig.adjust_for_frame(frame, SIZE_DUCK_SPRITE);
        RendererHelper::render(armorConfig, renderer, player.sprite.coordinate.get_x(),
                               player.sprite.coordinate.get_y() + 3, TILE_SIZE, TILE_SIZE);
    }

    if (static_cast<int>(player.inventory.weapon) != 0) {
        auto weapon_props =
                weapon_properties[static_cast<TEXTURE_WEAPONS>(player.inventory.weapon)];
        SDL2pp::Texture weapon_texture(renderer, weapon_props.texturePath);
        RenderConfig weaponConfig(weapon_texture, weapon_props.src_x, weapon_props.src_y,
                                  weapon_props.width, weapon_props.height, flip);
        RendererHelper::render(weaponConfig, renderer, get_offset_weapon_x(player),
                               get_offset_weapon_y(player), get_scale(player), get_scale(player));


        int x_ala = static_cast<orientations>(player.is_looking) == LEFT ?
                            player.sprite.coordinate.get_x() + 16 :
                            player.sprite.coordinate.get_x() + 12;


        RenderConfig playerAlaConfig(texture, 1, 566, SIZE_DUCK_ALA, SIZE_DUCK_ALA, flip);

        playerAlaConfig.adjust_for_frame(frame, SIZE_DUCK_ALA);

        RendererHelper::render(playerAlaConfig, renderer, x_ala,
                               player.sprite.coordinate.get_y() + 16, TILE_SIZE_ALA, TILE_SIZE_ALA);
    }
}
