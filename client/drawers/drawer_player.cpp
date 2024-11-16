#include "drawer_player.h"

#include <map>

#include "../../common/orientations.h"
#include "../game_state/player.h"


// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling

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

static std::map<TEXTURE_WEAPONS, weapon_properties_t> weaponProperties = {
        {GRANADA, {DATA_PATH "/DuckGame-Grenades.png", 1, 21, 15, 15}},
        {BANANA, {DATA_PATH "/DuckGame-Grenades.png", 1, 51, 15, 15}},
        {PEW_PEW_LASER, {DATA_PATH "/DuckGame-Laser.png", 336, 94, 32, 32}},
        {LASER_RIFLE, {DATA_PATH "/DuckGame-Laser.png", 1, 97, 32, 32}},
        {AK_47, {DATA_PATH "/DuckGame-MachineGuns.png", 1, 19, 32, 32}},
        {PISTOLA_DUELOS, {DATA_PATH "/DuckGame-Pistol.png", 35, 68, 18, 10}},
        {PISTOLA_COWBOY,
         {DATA_PATH "/DuckGame-Pistol.png", 0, 0, 0,
          0}},  // Sin coordenadas, me falta encontrar esta :(
        {MAGNUM, {DATA_PATH "/DuckGame-Pistol.png", 1, 47, 32, 32}},
        {ESCOPETA, {DATA_PATH "/DuckGame-Props.png", 60, 114, 41, 11}},
        {SNIPER, {DATA_PATH "/DuckGame-MoreWeapons.png", 36, 237, 33, 9}}};

// clave id_texture (para elegir el pato), valor struct(?)
static std::map<uint8_t, std::string> textures = {
        {DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
        {DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
        {DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
        {DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}};

DrawerPlayer::DrawerPlayer(player_t _player, SDL2pp::Renderer& renderer):
        player(_player), texture(renderer, textures[player.sprite.id_texture]) {}

void DrawerPlayer::draw(SDL2pp::Renderer& renderer) {
    // si está caminando, o no se si usan otro struct
    // yo tengo el nro de frame pero tengo que buscar la ubicacion en el sprite
    // Por default
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
                      this->player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        renderer.Copy(
                armadura,
                SDL2pp::Rect(armadura_src_x, armadura_src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                SDL2pp::Rect(player.sprite.coordinate.get_x(), player.sprite.coordinate.get_y() + 3,
                             TILE_SIZE, TILE_SIZE),
                0.0, SDL2pp::NullOpt,
                this->player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        /*renderer.Copy(armadura_para_alas, SDL2pp::Rect(armadura_alas_src_x, armadura_alas_y,
           SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE), SDL2pp::Rect(player.sprite.coordinate.get_x(),
           player.sprite.coordinate.get_y() + 3, TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                      this->player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);*/

        renderer.Copy(casco, SDL2pp::Rect(casco_src_x, casco_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                      SDL2pp::Rect(player.sprite.coordinate.get_x() - 4,
                                   player.sprite.coordinate.get_y() - 16, TILE_SIZE, TILE_SIZE),
                      0.0, SDL2pp::NullOpt,
                      this->player.is_looking == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    }

    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                  SDL2pp::Rect(player.sprite.coordinate.get_x(), player.sprite.coordinate.get_y(),
                               TILE_SIZE, TILE_SIZE),
                  0.0, SDL2pp::NullOpt,
                  static_cast<orientations>(this->player.is_looking) == LEFT ? SDL_FLIP_HORIZONTAL :
                                                                               SDL_FLIP_NONE);

    if (static_cast<int>(player.inventory.weapon) != 0) {

        auto& properties = weaponProperties[static_cast<TEXTURE_WEAPONS>(player.inventory.weapon)];
        weaponTexture = SDL2pp::Texture(renderer, properties.texturePath);
        int weaponsrc_X = properties.src_x;
        int weaponsrc_Y = properties.src_y;
        int weapon_width = properties.width;
        int weapon_height = properties.height;
        renderer.Copy(weaponTexture,
                      SDL2pp::Rect(weaponsrc_X, weaponsrc_Y, weapon_width, weapon_height),
                      SDL2pp::Rect(player.sprite.coordinate.get_x(),
                                   player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE));
    }
}


void DrawerPlayer::update_player(const player_t& updated_player) { player = updated_player; }
