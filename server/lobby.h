#ifndef LOBBY_H
#define LOBBY_H

#include <cstdint>
#include <list>

#include "../common/queue.h"

#include "event.h"
#include "game.h"
#include "game_state.h"
#include "monitor_clients.h"


class Lobby {
private:
    MonitorClients monitor_clients;
    std::list<int> players_id;
    Queue<Event*> queue_event;
    Queue<GameState_t> queue_gamestate;
    Game game;

    // void init_player_list();

public:
    Lobby();
    void run();
    ~Lobby();
};

#endif
