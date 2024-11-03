#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../common/coordinate.h"
#include "../common/queue.h"

#include "keyboard_controller.h"

class Drawer {
private:
    Queue<ClientEvent_t>& commands;
    Queue<std::vector<PlayerPosition_t>>& positions;
    KeyboardController keyboard_controller;

    void controlar_movimiento_pato(bool& is_running, bool& is_moving_left,
                                   std::vector<PlayerPosition_t>& position,
                                   unsigned int& frame_delta, int& run_phase,
                                   unsigned int& frame_tricks);

public:
    /*
     * Constructor.
     */
    Drawer(Queue<ClientEvent_t>& commands, Queue<std::vector<PlayerPosition_t>>& positions);

    /*
     *
     */
    void run();

    /*
     * Deshabilitar copias.
     */
    Drawer(const Drawer&) = delete;
    Drawer& operator=(const Drawer&) = delete;
};

#endif  // DRAWER_H
