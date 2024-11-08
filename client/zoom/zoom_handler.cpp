#include "zoom_handler.h"

// Window
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

#define MARGEN 200 // ojimetro, así no hace zoom cuando está muy al borde

#define OFFSET_X 200
#define OFFSET_Y 200

// TAMAÑO TILESET EN LA PANTALLA
#define TILE_SIZE 50  // 50x50 // Size of the tile in pixels after scaling

ZoomHandler::ZoomHandler(): dest_x(0), dest_y(0), factor_zoom(0.0) {}

void ZoomHandler::calculate_zoom(const std::vector<PlayerPosition_t>& positions) {
    if (positions.empty()) return;  // si no hay patos, no hacemos nada, no deberia entrar a esto pero lo dejo por seguridad

    // calculamos los límites (mínimo y máximo) del área que contiene todos los patos, tomamos por defecto al primer pato
    int min_x = positions[0].coordinate.get_x();
    int max_x = positions[0].coordinate.get_x();
    int min_y = positions[0].coordinate.get_y();
    int max_y = positions[0].coordinate.get_y();

    // vamos actualizando los minimos y maximos en base al resto de los patos
    for (const auto& position : positions) {
        int x = position.coordinate.get_x();
        int y = position.coordinate.get_y();
        if (x < min_x) min_x = x;
        if (x > max_x) max_x = x;
        if (y < min_y) min_y = y;
        if (y > max_y) max_y = y;
    }
    // Minimo X y minimo Y es esquina superior izquierda
    // Maximo x y maximo Y es esquina inferior derecha

    std::cout << "(min_x, min_y, max_x, max_y): (" << min_x << " "<<  min_y << " " << max_x << " " << max_y << ")" << std::endl;

    // calculamos el ancho y alto del área que contiene todos los patos
    int area_width = max_x - min_x;
    int area_height = max_y - min_y;

    // calculamos el factor de zoom necesario para ajustar el área dentro de la ventana
    float zoom_x = static_cast<float>(WINDOW_WIDTH) / (area_width + MARGEN);  // Agrega TILE_SIZE para un poco de margen
    float zoom_y = static_cast<float>(WINDOW_HEIGHT) / (area_height + MARGEN);

    // usamos el factor de zoom más pequeño para asegurarse de que todo se vea
    factor_zoom = std::min(zoom_x, zoom_y);
    std::cout << "este es el factor zoom " << factor_zoom << std::endl;
    
    if (factor_zoom == 10) { // ojimetro
        dest_width = WINDOW_WIDTH;
        dest_height = WINDOW_HEIGHT;
        return;
    }

    // if (factor_zoom > 1.0) factor_zoom = 1.0;  // No permitimos hacer zoom más grande que 1 (sin acercar demasiado)

    // calculamos el tamaño de destino para zoom
    dest_width = WINDOW_WIDTH * factor_zoom;
    dest_height = WINDOW_HEIGHT * factor_zoom;

    // calculamos dest_x y dest_y para centrar el área en la ventana
    int center_x = (min_x + max_x) / 2;
    int center_y = (min_y + max_y) / 2;
    
    dest_x = WINDOW_WIDTH / 2 - (center_x * factor_zoom);
    dest_y = WINDOW_HEIGHT / 2 - (center_y * factor_zoom);

    //esto le agrega offset pero se pierde de foco
    dest_x = WINDOW_WIDTH / 2 - (center_x * factor_zoom) - OFFSET_X;
    dest_y = WINDOW_HEIGHT / 2 - (center_y * factor_zoom) - OFFSET_Y;       
}

/*
void ZoomHandler::calculate_zoom(const std::vector<PlayerPosition_t>& position) {
    // Calcular el tamaño de destino para zoom
    dest_width = WINDOW_WIDTH * FACTOR_ZOOM;  // ajustar el factor de zoom
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
}*/

void ZoomHandler::apply_zoom(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture) {
    renderer.Copy(texture, SDL2pp::NullOpt, SDL2pp::Rect(dest_x, dest_y, dest_width, dest_height));
}
