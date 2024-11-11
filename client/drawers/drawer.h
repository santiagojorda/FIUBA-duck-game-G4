#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../../common/coordinate.h"
#include "../../common/queue.h"
#include "../game_state/player.h"
#include "../keyboard/keyboard_controller.h"
#include "../zoom/zoom_handler.h"

#include "drawer_box.h"
#include "drawer_duck.h"
#include "drawer_player.h"
#include "drawer_weapon.h"

#include "../../common/state_duck.h"

class Drawer {
private:
    Queue<ClientEvent_t>& commands;
    Queue<client_game_state_t>& game_state;
    KeyboardController keyboard_controller;

public:
    /*
     * Constructor.
     */
    Drawer(Queue<ClientEvent_t>& commands, Queue<client_game_state_t>& game_state);

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
