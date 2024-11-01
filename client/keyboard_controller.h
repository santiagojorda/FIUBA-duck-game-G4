#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../common/queue.h"

class KeyboardController {
private:
    Queue<uint8_t>& commands;
public:
    /*
     * Constructor.
     */
    KeyboardController(Queue<uint8_t>& _commands);


    // el is_running y moving_left luego se van
    /*
     * Event processing:
     * - If window is closed, or Q or Escape buttons are pressed, quit the application.
     * - If Right key is pressed, character would run.
     * - If Right key is released, character would stop.
     */

    void procesar_comando(SDL_Event& event, bool& is_running, bool& is_moving_left);
};

#endif  // KEYBOARD_CONTROLLER_H
