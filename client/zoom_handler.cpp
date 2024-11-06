#include "zoom_handler.h"

// Window
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling

#define FACTOR_ZOOM 1

ZoomHandler::ZoomHandler(): dest_x(0), dest_y(0) {}

void ZoomHandler::calculate_zoom(const std::vector<PlayerPosition_t>& position) {
    // Calcular el tamaño de destino para zoom
    dest_width = WINDOW_WIDTH * FACTOR_ZOOM;  // Ajusta el factor de zoom como prefieras
    dest_height = WINDOW_HEIGHT * FACTOR_ZOOM;
    
    if (FACTOR_ZOOM != 1.0) {
        // calculamos dest_x y dest_y basados en la posición del pato
        // Si el factor de zoom no es 1, centramos el zoom en la posición del pato
        // si no hago esto:el zoom podría aparecer desplazado o desalineado respecto al pato
        // tomamos la posición del pato para centrar el zoom en este
        int duck_x = position[0].coordinate.get_x();
        int duck_y = position[0].coordinate.get_y();

        dest_x = WINDOW_WIDTH / 2 - (duck_x * FACTOR_ZOOM);
        dest_y = WINDOW_HEIGHT / 2 - (duck_y * FACTOR_ZOOM);
    }
}

void ZoomHandler::apply_zoom(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture) {
    renderer.Copy(texture, SDL2pp::NullOpt, SDL2pp::Rect(dest_x, dest_y, dest_width, dest_height));
}
