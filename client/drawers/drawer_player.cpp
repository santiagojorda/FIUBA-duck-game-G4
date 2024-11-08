#include "drawer_player.h"

#include <map>

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
/*static const std::map<uint8_t, std::string> textures = {
                                                 {DUCK_YELLOW, DATA_PATH "/DuckGame-YellowDuck.png"},
                                                 {DUCK_GREY, DATA_PATH "/DuckGame-GreyDuck.png"},
                                                 {DUCK_ORANGE, DATA_PATH "/DuckGame-OrangeDuck.png"},
                                                 {DUCK_WHITE, DATA_PATH "/DuckGame-WhiteDuck.png"}
                                                 };


*/

DrawerPlayer::DrawerPlayer(player_t player, SDL2pp::Renderer& renderer): player(player), texture(renderer, DATA_PATH "/DuckGame-YellowDuck.png") {}


void DrawerPlayer::draw(SDL2pp::Renderer& renderer) {

}
