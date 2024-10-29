#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include <list>

#include "../common/queue.h"
#include "../common/socket.h"
#include "../common/thread.h"

#include "acceptor.h"
#include "event.h"
#include "game_state.h"
#include "monitor_clients.h"

class AcceptorClients: public Acceptor {
private:
    Socket skt;

    MonitorClients& monitor;
    Queue<GameState_t>& queue_gamestate;
    Queue<Event*>& queue_event;
    std::list<int>& players_id;

    void create_client();
    void listen_new_client();

public:
    AcceptorClients(MonitorClients& monitor, Queue<GameState_t>& _queue_gamestate,
                    Queue<Event*>& _queue_event, std::list<int>& _players_id);
    void run() override;
    void stop() override;
};

#endif
