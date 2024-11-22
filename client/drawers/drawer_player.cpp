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


DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& player):
        texture(renderer, textures[player.sprite.id_texture]) {}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {
    bool flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    DuckStateType duck_state = static_cast<DuckStateType>(player.state);
    int duck_x = player.sprite.coordinate.get_x();
    int duck_y = player.sprite.coordinate.get_y();
    int frame = static_cast<int>(player.frame);
    std::cout  << "player state: "<< static_cast<int>(player.state) << "\n";

    switch (duck_state) {
    case DuckStateType::IS_IDLE:
        renderer.Copy(this->texture,
                      SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * 0), 
                                    DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * 0), 
                                    SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                      flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
        break;
    case DuckStateType::IS_CROUCHING:
        renderer.Copy(this->texture,
                      SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * DUCK_SPRITE_CROUCHING_X), 
                                    DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * DUCK_SPRITE_CROUCHING_Y), 
                                    SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                      flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
        break;
    case DuckStateType::IS_FALLING:
        
        break;
    case DuckStateType::IS_JUMPING:
        std::cout << "frame: " << frame << "\n";
        
        /*
        renderer.Copy(this->texture,
                      SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * DUCK_SPRITE_CROUCHING_X), 
                                    DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * DUCK_SPRITE_CROUCHING_Y), 
                                    SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                      flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);*/
        break;
    case DuckStateType::IS_DEAD:
        std::cout << "Muere "  << "\n";

        break;
    case DuckStateType::IS_PLANNING:
        std::cout << "Planea "  << "\n";
        break;
    case DuckStateType::IS_RECOILING:
        std::cout << "recoiling? "  << "\n";
        break;
    case DuckStateType::IS_SLIPPING:
        std::cout << "Se resbala "  << "\n";
        break;
    case DuckStateType::IS_RUNNING:
        std::cout << "frame: " << frame << "\n";

        renderer.Copy(this->texture,
                      SDL2pp::Rect(DUCK_IDLE_X + (SIZE_DUCK_SPRITE * frame), 
                                    DUCK_IDLE_Y + (SIZE_DUCK_SPRITE * frame), 
                                    SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(duck_x, duck_y, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                      flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
        break;
    default: 
        break;
    }

}

/** 
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
                           player.sprite.coordinate.get_y() - OFFSET_Y, TILE_SIZE, TILE_SIZE);

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
        auto weapon_id = static_cast<WeaponTextureID>(player.inventory.weapon);
        auto weapon_props = weapon_properties[weapon_id];
        SDL2pp::Texture weapon_texture(renderer, weapon_props.texturePath);
        RenderConfig render_config(weapon_texture, weapon_props.src_x, weapon_props.src_y,
                                   weapon_props.width, weapon_props.height, flip);

        WeaponConfig weapon_config(weapon_id, flip, player.sprite.coordinate);
        RendererHelper::render(render_config, renderer, weapon_config.offset_x,
                               weapon_config.offset_y - OFFSET_Y, weapon_config.scale_width,
                               weapon_config.scale_height);

        int x_ala = flip ? 16 : 12;
        RenderConfig playerAlaConfig(texture, 1, 566, SIZE_DUCK_ALA, SIZE_DUCK_ALA, flip);
        playerAlaConfig.adjust_for_frame(frame, SIZE_DUCK_ALA);
        RendererHelper::render(playerAlaConfig, renderer, player.sprite.coordinate.get_x() + x_ala,
                               player.sprite.coordinate.get_y() + 16 - OFFSET_Y, TILE_SIZE_ALA,
                               TILE_SIZE_ALA);
    }
    */