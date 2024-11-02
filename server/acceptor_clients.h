#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include <list>

#include "../common/socket.h"
#include "../common/thread.h"

#include "acceptor.h"
#include "event_player.h"
#include "list_players_id.h"
#include "monitor_clients.h"
#include "queue_event_player.h"
#include "queue_game_state.h"

class AcceptorClients: public Acceptor {
private:
    MonitorClients& monitor;
    QueueGameState& queue_gamestate;
    QueueEventPlayer& queue_event;
    ListPlayersID& players_id;

    void create_client();
    void listen_new_client();

public:
    AcceptorClients(MonitorClients& monitor, QueueGameState& _queue_gamestate,
                    QueueEventPlayer& _queue_event, ListPlayersID& _players_id);
    void run() override;
    void stop() override;
    ~AcceptorClients();
};

#endif
