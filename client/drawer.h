#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../common/coordinate.h"
#include "../common/queue.h"

#include "drawer_duck.h"
#include "keyboard_controller.h"
#include "zoom_handler.h"

class Drawer {
private:
    Queue<ClientEvent_t>& commands;
    Queue<std::vector<PlayerPosition_t>>& game_state;
    KeyboardController keyboard_controller;

    void controlar_movimiento_pato(bool& is_running, bool& is_moving_left,
                                   std::vector<PlayerPosition_t>& position,
                                   unsigned int& frame_delta, int& run_phase,
                                   unsigned int& frame_tricks);

public:
    /*
     * Constructor.
     */
    Drawer(Queue<ClientEvent_t>& commands, Queue<std::vector<PlayerPosition_t>>& game_state);

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
