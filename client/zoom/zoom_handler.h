#ifndef ZOOM_HANDLER_H
#define ZOOM_HANDLER_H

#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "../game_state/vector_player.h"

class ZoomHandler {
private:
    int dest_x;
    int dest_y;
    float factor_zoom;
    int dest_width;   // para ajustar el factor del zoom
    int dest_height;  // para ajustar el factor del zoom

public:
    /*
     * Constructor.
     */
    ZoomHandler();

    void calculate_zoom(const VectorPlayers& players);

    void apply_zoom(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture);

    /*
     * Deshabilitar copias.
     */
    ZoomHandler(const ZoomHandler&) = delete;
    ZoomHandler& operator=(const ZoomHandler&) = delete;
};

#endif  // ZOOM_HANDLER_H
