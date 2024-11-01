#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../common/coordinate.h"
#include "../common/queue.h"

#include "keyboard_controller.h"

class Drawer {
private:
    Queue<uint8_t>& commands;
    Queue<std::vector<Coordinate>>& positions;
    KeyboardController keyboard_controller;

    void controlar_movimiento_pato(bool& is_running, bool& is_moving_left,
                                   std::vector<Coordinate>& position, unsigned int& frame_delta,
                                   int& run_phase, unsigned int& frame_tricks);

public:
    /*
     * Constructor.
     */
    Drawer(Queue<uint8_t>& commands, Queue<std::vector<Coordinate>>& positions);

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
