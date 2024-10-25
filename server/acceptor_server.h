#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include <string>

#include "../common/socket.h"
#include "../common/thread.h"

#include "acceptor.h"

class AcceptorServer: public Acceptor {
private:
    Socket skt;

    void create_server();
    void listen_new_server();

public:
    AcceptorServer(const std::string& servaname);
    void run() override;
    void stop() override;
};

#endif
