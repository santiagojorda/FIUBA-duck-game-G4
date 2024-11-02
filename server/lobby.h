#ifndef LOBBY_H
#define LOBBY_H

#include <cstdint>
#include <list>

#include "../common/queue.h"

#include "event_player.h"
#include "game.h"
#include "game_state.h"
#include "list_players_id.h"
#include "monitor_clients.h"

class Lobby {
private:
    MonitorClients monitor_clients;
    ListPlayersID players_id;
    ListPlayers players;
    Queue<EventPlayer*> queue_event;
    Queue<GameState_t> queue_gamestate;

    void init_players();
    void init_game();
    void accept_clients();

public:
    Lobby();
    void run();
    ~Lobby();
};

#endif
