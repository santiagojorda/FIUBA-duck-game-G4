#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include "../common/socket.h"
#include "../common/thread.h"

#include "acceptor.h"
#include "monitor_clients.h"

class AcceptorPlayer: public Acceptor {
private:
    Socket skt;

    MonitorClients& monitor_client;

    void create_player();
    void listen_new_player();

public:
    AcceptorPlayer();
    void run() override;
    void stop() override;
};

#endif
