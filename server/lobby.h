#ifndef LOBBY_H
#define LOBBY_H

#include <list>
#include <cstdint>
#include "monitor_clients.h"
#include "game.h"

#include "game_state.h"
#include "event.h"
#include "../common/queue.h"


class Lobby {
private:
    MonitorClients monitor_clients;
    std::list<int> players_id;
    Game game;
    Queue<Event*> queue_event;
    Queue<GameState_t> queue_gamestate;

    // void init_player_list();

public:
    Lobby();
    ~Lobby();
};

#endif
