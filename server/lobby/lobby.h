#ifndef LOBBY_H
#define LOBBY_H

#include <list>

#include "../game/game.h"
#include "../player/list_players_id.h"
#include "../client/monitor_clients.h"
#include "../events/queue_event_player.h"
#include "../game/queue_game_state.h"

class Lobby {
private:
    MonitorClients monitor_clients;
    ListPlayersID players_id;
    ListPlayers players;
    QueueEventPlayer queue_event;
    QueueGameState queue_gamestate;

    void init_players();
    void init_game();
    void accept_clients();

public:
    Lobby();
    void run();
    ~Lobby();
};

#endif
