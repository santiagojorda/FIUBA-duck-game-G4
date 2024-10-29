#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

class KeyboardController {
private:
public:
    /*
     * Constructor.
     */
    KeyboardController();


    // el is_running y moving_left luego se van
    void procesar_comando(SDL_Event& event, bool& is_running, bool& is_moving_left);
};

#endif  // KEYBOARD_CONTROLLER_H
