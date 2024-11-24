#include "drawer_player.h"

#include <map>

#include "../../common/direction.h"
#include "../../common/weapons_id.h"
#include "../game_state/player.h"

#define TILE_SIZE_ALA 22
#define SIZE_DUCK_ALA 16
#define OFFSET_Y 12

/* Initial values */
#define SIZE_DUCK_SPRITE 32
#define DUCK_IDLE_X 1
#define DUCK_IDLE_Y 11

#define DUCK_SPRITE_CROUCHING_X 5
#define DUCK_SPRITE_CROUCHING_Y 1

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id,
                           std::map<std::string, Animation>& _animations, uint8_t is_looking):
        Drawable<Animation>(renderer,
                            std::make_unique<SDL2pp::Texture>(renderer, textures_ducks[texture_id]),
                            _animations, static_cast<Direction>(is_looking) == Direction::LEFT) {}

void DrawerPlayer::draw(const player_t& player) {
    this->flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    this->coordenada_x = player.sprite.coordinate.get_x();
    this->coordenada_y = player.sprite.coordinate.get_y() - OFFSET_Y;
    this->scale_height = TILE_SIZE;
    this->scale_width = TILE_SIZE;
    this->frame = static_cast<int>(player.frame);

    DuckStateType duck_state = static_cast<DuckStateType>(player.state);

    std::string type_action = textures_action_ducks.at(duck_state);
    this->update_animation(type_action);

    if (static_cast<int>(player.inventory.armor) != 0) {
        SDL2pp::Texture armadura_texture(renderer, DATA_PATH "/DuckGame-Equipment.png");
        RenderConfig armorConfig(armadura_texture, 387, 11, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE,
                                 flip);
        armorConfig.adjust_for_frame(frame, SIZE_DUCK_SPRITE);
        RendererHelper::render(armorConfig, renderer, player.sprite.coordinate.get_x(),
                               player.sprite.coordinate.get_y() + 3 - OFFSET_Y, TILE_SIZE,
                               TILE_SIZE);
    }

    if (static_cast<int>(player.inventory.weapon) != 0) {
        std::cout << "tatic_cast<int>(player.inventory.weapon): " << static_cast<int>(player.inventory.weapon) << "\n";
        auto weapon_id = static_cast<WeaponTextureID>(player.inventory.weapon);
        auto weapon_props = weapon_properties[weapon_id];
        SDL2pp::Texture weapon_texture(renderer, weapon_props.texturePath);
        RenderConfig render_config(weapon_texture, weapon_props.src_x, weapon_props.src_y,
                                   weapon_props.width, weapon_props.height, flip);

        WeaponConfig weapon_config(weapon_id, flip, player.sprite.coordinate);
        RendererHelper::render(render_config, renderer, weapon_config.offset_x,
                               weapon_config.offset_y - 10, weapon_config.scale_width,
                               weapon_config.scale_height);

        int x_ala = flip ? 16 : 12;
        RenderConfig playerAlaConfig(*this->texture, 1, 566, SIZE_DUCK_ALA, SIZE_DUCK_ALA, flip);
        playerAlaConfig.adjust_for_frame(frame, SIZE_DUCK_ALA);
        RendererHelper::render(playerAlaConfig, renderer, this->coordenada_x + x_ala,
                               this->coordenada_y + 16, TILE_SIZE_ALA, TILE_SIZE_ALA);
    }
}

void DrawerPlayer::update_animation(const std::string type_animation) {
    auto anim = this->animations[type_animation].get_current_frame(this->frame);
    render(anim);
}

void DrawerPlayer::update_inventory() {}
