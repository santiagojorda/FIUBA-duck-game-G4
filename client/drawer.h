#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../common/queue.h"

#include "keyboard_controller.h"

class Drawer {
private:
    KeyboardController keyboard_controller;
    Queue<std::vector<uint8_t>>& commands;
    Queue<std::vector<Coordinate>>& positions;

    void controlar_movimiento_pato(bool& is_running, bool& is_moving_left, float& position,
                                   unsigned int& frame_delta, int& run_phase,
                                   unsigned int& frame_tricks);

public:
    /*
     * Constructor.
     */
    Drawer();

    /*
     *
     */
    void run(Queue<std::vector<uint8_t>>& commands, Queue<std::vector<Coordinate>>& positions);

    /*
     * Deshabilitar copias.
     */
    Drawer(const Drawer&) = delete;
    Drawer& operator=(const Drawer&) = delete;
};

#endif  // DRAWER_H
