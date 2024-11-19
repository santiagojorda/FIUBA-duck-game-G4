#include "drawer_player.h"

#include <map>

#include "../../common/direction.h"
#include "../../common/weapons_id.h"
#include "../game_state/player.h"

#define TILE_SIZE_ALA 22

#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32
#define SIZE_DUCK_ALA 16

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& player):
        texture(renderer, textures[player.sprite.id_texture]) {}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {
    bool flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;

    int x_duck = static_cast<DuckStateType>(player.state) == DuckStateType::IS_CROUCHING ?
                         DUCK_INITIAL_X + SIZE_DUCK_SPRITE * 2 :
                         DUCK_INITIAL_X;
    int y_duck = static_cast<DuckStateType>(player.state) == DuckStateType::IS_CROUCHING ?
                         DUCK_INITIAL_Y + SIZE_DUCK_SPRITE * 6 :
                         DUCK_INITIAL_Y;

    RenderConfig playerConfig(texture, x_duck, y_duck, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE, flip);
    int frame = static_cast<DuckStateType>(player.state) == DuckStateType::IS_RUNNING ?
                        player.frame :
                        0;
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
        auto weapon_id = static_cast<WeaponTextureID>(player.inventory.weapon);
        auto weapon_props = weapon_properties[weapon_id];
        SDL2pp::Texture weapon_texture(renderer, weapon_props.texturePath);
        RenderConfig render_config(weapon_texture, weapon_props.src_x, weapon_props.src_y,
                                   weapon_props.width, weapon_props.height, flip);

        WeaponConfig weapon_config(weapon_id, flip, player.sprite.coordinate);
        RendererHelper::render(render_config, renderer, weapon_config.offset_x,
                               weapon_config.offset_y, weapon_config.scale_width,
                               weapon_config.scale_height);

        int x_ala = flip ? 16 : 12;
        RenderConfig playerAlaConfig(texture, 1, 566, SIZE_DUCK_ALA, SIZE_DUCK_ALA, flip);
        playerAlaConfig.adjust_for_frame(frame, SIZE_DUCK_ALA);
        RendererHelper::render(playerAlaConfig, renderer, player.sprite.coordinate.get_x() + x_ala,
                               player.sprite.coordinate.get_y() + 16, TILE_SIZE_ALA, TILE_SIZE_ALA);
    }
}
