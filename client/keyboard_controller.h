#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../common/queue.h"
#include "../common/socket.h"
#include "protocol/protocol_client.h"

#include "client_event.h"
class KeyboardController {
private:
    Queue<ClientEvent_t>& commands;
    int num_players;

    void procesar_keyup(SDL_Event& event, bool& is_running);

    void procesar_keydown(SDL_Event& event, bool& is_running, bool& is_moving_left);

    void procesar_accion_player_1(SDL_Event& event, bool& is_running, bool& is_moving_left);

    void procesar_accion_player_2(SDL_Event& event, bool& is_running, bool& is_moving_left);

public:
    /*
     * Constructor.
     */
    KeyboardController(Queue<ClientEvent_t>& _commands, int num_players);


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
