#ifndef ZOOM_HANDLER_H
#define ZOOM_HANDLER_H

#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "../player_position.h"

class ZoomHandler {
private:
    int dest_x;
    int dest_y;
    int dest_width;
    int dest_height;

public:
    /*
     * Constructor.
     */
    ZoomHandler();

    void calculate_zoom(const std::vector<PlayerPosition_t>& positions);

    void apply_zoom(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture);

    /*
     * Deshabilitar copias.
     */
    ZoomHandler(const ZoomHandler&) = delete;
    ZoomHandler& operator=(const ZoomHandler&) = delete;
};

#endif  // ZOOM_HANDLER_H
