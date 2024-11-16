#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

#include "../../common/coordinate.h"
#include "../../common/queue.h"
#include "../../common/socket.h"
#include "../../common/state_duck.h"
#include "../config/game_config.h"
#include "../game_state/player.h"
#include "../keyboard/keyboard_controller.h"
#include "../protocol/protocol_client.h"
#include "../zoom/zoom_handler.h"

#include "drawer_box.h"
#include "drawer_floor.h"
#include "drawer_player.h"
#include "drawer_weapon.h"

struct drawers_t {
    std::map<uint8_t, std::unique_ptr<DrawerPlayer>> players;
    std::vector<std::unique_ptr<DrawerFloor>> floors;
    std::vector<std::unique_ptr<DrawerBox>> boxes;
    std::vector<std::unique_ptr<DrawerWeapon>> weapons;
};

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
     *
     */
    void init_scenery(SDL2pp::Renderer& renderer, const client_game_state_t& actual_game_state,
                      drawers_t& drawers);

    /*
     * Deshabilitar copias.
     */
    Drawer(const Drawer&) = delete;
    Drawer& operator=(const Drawer&) = delete;
};

#endif  // DRAWER_H
