#include "drawer_player.h"

#include <map>


#include "../game_state/player.h"
#include "../../common/orientations.h"


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

// clave id_texture (para elegir el pato), valor struct(?9)
static  std::map<uint8_t, std::string> textures = {
                                                 {DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
                                                 {DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
                                                 {DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
                                                 {DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}
                                                 };




DrawerPlayer::DrawerPlayer(player_t _player, SDL2pp::Renderer& renderer): player(_player), texture(renderer, textures[player.sprite.id_texture]) {}


void DrawerPlayer::draw(SDL2pp::Renderer& renderer) {
    int src_x = DUCK_INITIAL_X + SIZE_DUCK_SPRITE /** run_phase;*/;
    int src_y = DUCK_INITIAL_Y;
    renderer.Copy(texture, SDL2pp::Rect(src_x, src_y, SIZE_DUCK_SPRITE, SIZE_DUCK_SPRITE),
                  SDL2pp::Rect(player.sprite.coordinate.get_x(), player.sprite.coordinate.get_y(), TILE_SIZE, TILE_SIZE), 0.0, SDL2pp::NullOpt,
                  this->player.is_looking ==  LEFT? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}
