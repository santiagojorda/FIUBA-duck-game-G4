#include "drawer_player.h"

#include <map>

#include "../../common/orientations.h"
#include "../game_state/player.h"

#define TILE_SIZE_WEAPON 40

// (X,Y) DEL PATO PARA ESTAR QUIETO Y CAMINAR DEL SPRITE
#define DUCK_INITIAL_X 1
#define DUCK_INITIAL_Y 11
#define SIZE_DUCK_SPRITE 32
#define CANT_ANIMATION_RUN 6  // para la fase de animacion

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

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, const player_t& player):
        texture(renderer, textures[player.sprite.id_texture]) {}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer, const player_t& player) {
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
        // no hago nada, se quedan con los valores por defecto, verlo luego.
    } else if (player.state == 100) {  // posee armadura -> Consultar cual es el estado
        renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x(),
                                   player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE),
                      0.0, SDL2pp::NullOpt,
                      player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        renderer.Copy(
                armadura,
                SDL2pp::Rect(armadura_src_x, armadura_src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                SDL2pp::Rect(player.sprite.coordinate.get_x(), player.sprite.coordinate.get_y() + 3,
                             TILE_SIZE, TILE_SIZE),
                0.0, SDL2pp::NullOpt,
                player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        renderer.Copy(casco, SDL2pp::Rect(casco_src_x, casco_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x() - 4,
                                   player.sprite.coordinate.get_y() - 16, TILE_SIZE, TILE_SIZE),
                      0.0, SDL2pp::NullOpt,
                      player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    }

    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                  SDL2pp::Rect(player.sprite.coordinate.get_x(), player.sprite.coordinate.get_y(),
                               TILE_SIZE, TILE_SIZE),
                  0.0, SDL2pp::NullOpt,
                  static_cast<orientations>(player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                         SDL_FLIP_NONE);

    if (static_cast<int>(player.inventory.weapon) != 0) {
        auto& properties = weapon_properties[static_cast<TEXTURE_WEAPONS>(player.inventory.weapon)];
        weaponTexture = SDL2pp::Texture(renderer, properties.texturePath);
        int weaponsrc_X = properties.src_x;
        int weaponsrc_Y = properties.src_y;
        int weapon_width = properties.width;
        int weapon_height = properties.height;
        renderer.Copy(weaponTexture,
                      SDL2pp::Rect(weaponsrc_X, weaponsrc_Y, weapon_width, weapon_height),
                      SDL2pp::Rect(player.sprite.coordinate.get_x() + 3,
                                   player.sprite.coordinate.get_y() + 5, TILE_SIZE_WEAPON,
                                   TILE_SIZE_WEAPON));
    }
}
