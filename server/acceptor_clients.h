#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include <list>

#include "../common/queue.h"
#include "../common/socket.h"
#include "../common/thread.h"

#include "acceptor.h"
#include "event_player.h"
#include "game_state.h"
#include "list_players_id.h"
#include "monitor_clients.h"

class AcceptorClients: public Acceptor {
private:
    MonitorClients& monitor;
    Queue<GameState_t>& queue_gamestate;
    Queue<EventPlayer*>& queue_event;
    ListPlayersID& players_id;

    void create_client();
    void listen_new_client();

public:
    AcceptorClients(MonitorClients& monitor, Queue<GameState_t>& _queue_gamestate,
                    Queue<EventPlayer*>& _queue_event, ListPlayersID& _players_id);
    void run() override;
    void stop() override;
    ~AcceptorClients();
};

#endif
