#include "zoom_handler.h"

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

#define OFFSET 100

ZoomHandler::ZoomHandler(): dest_x(0), dest_y(0), factor_zoom(0.0) {}

void ZoomHandler::calculate_zoom(const VectorPlayers& players) {
    if (players.empty())
        return;

    int min_x = players[0].sprite.coordinate.get_x();
    int max_x = players[0].sprite.coordinate.get_x();
    int min_y = players[0].sprite.coordinate.get_y();
    int max_y = players[0].sprite.coordinate.get_y();

    for (const auto& position: players) {
        int x = position.sprite.coordinate.get_x();
        int y = position.sprite.coordinate.get_y();
        if (x < min_x)
            min_x = x;
        if (x > max_x)
            max_x = x;
        if (y < min_y)
            min_y = y;
        if (y > max_y)
            max_y = y;
    }

    int ancho = max_x - min_x;
    int altura = max_y - min_y;

    int auxiliar = 0;

    if (ancho != 0 && altura != 0) {
        auxiliar = ancho * altura;
    } else if (ancho == 0) {
        auxiliar = altura;
    } else {
        auxiliar = ancho;
    }

    float zoom_x = ancho == 0 ? 0 : static_cast<float>(WINDOW_WIDTH) / (ancho + OFFSET);
    float zoom_y = altura == 0 ? 0 : static_cast<float>(WINDOW_HEIGHT) / (altura + OFFSET);

    if (zoom_x != 0 && zoom_y != 0) {
        factor_zoom = std::min(zoom_x, zoom_y);
    } else if (zoom_x == 0) {
        factor_zoom = zoom_y;
    } else {
        factor_zoom = zoom_x;
    }

    if (factor_zoom == 0 || factor_zoom >= 1.6) {
        factor_zoom = 1.6;
    }

    dest_width = WINDOW_WIDTH * factor_zoom;
    dest_height = WINDOW_HEIGHT * factor_zoom;
    int center_x = (min_x + max_x) / 2;
    int center_y = (min_y + max_y) / 2;
    dest_x = WINDOW_WIDTH / 2 - (center_x * factor_zoom);
    dest_y = WINDOW_HEIGHT / 2 - (center_y * factor_zoom);
}

void ZoomHandler::apply_zoom(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture) {
    SDL2pp::Rect zoom_rect(dest_x, dest_y, dest_width, dest_height);
    renderer.Copy(texture, SDL2pp::NullOpt, zoom_rect);
}
