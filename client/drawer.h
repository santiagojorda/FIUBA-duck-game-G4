#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "keyboard_controller.h"

class Drawer {
private:
    /*
     * Event processing:
     * - If window is closed, or Q or Escape buttons are pressed, quit the application.
     * - If Right key is pressed, character would run.
     * - If Right key is released, character would stop.
     */

    KeyboardController keyboard_controller;
    void run_command(SDL_Event& event, bool& is_running, bool& is_moving_left);

public:
    /*
     * Constructor.
     */
    Drawer();

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
